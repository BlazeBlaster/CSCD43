#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/timeb.h>
#include "library.h"

using namespace std;

#define Rec_Size 1000
#define Num_Columns 100

#define Buf_Size (10 * 100 + (100 - 1) + 1)

int main(int argc, char **argv)
{
    printf("HERE\n");
    if (argc != 4)
    {
        printf("Usage: %s <csv file> <page file> <page size>\n", argv[0]);
        return 1;
    }

    size_t page_size = atoi(argv[3]);
    ifstream csv;
    csv.open(argv[1]);

    ofstream page;
    page.open(argv[2], ofstream::binary);

    Page *pagefile = new Page;
    init_fixed_len_page(pagefile, page_size, Rec_Size);

    int maxRecords = fixed_len_page_capacity(pagefile);
    cout << "MAX RECORDS: " << maxRecords;
    string line;

    int numPages = 0;
    int numRecords = 0;
    double diff;
    int i = 0;

    struct timeb before;
    struct timeb after;
    int slot;
    ftime(&before);
    long now_in_ms = before.time * 1000 + before.millitm;
    while (getline(csv, line))
    {
        Record *r = NULL;
        r = new Record;
        istringstream field(line);
        string attribute;
        while (getline(field, attribute, ','))
        {
            char *cstr = new char[strlen(attribute.c_str()) + 1];
            strcpy(cstr, attribute.c_str());
            r->push_back(cstr);
            //cout << cstr << '\n';
        }

        slot = add_fixed_len_page(pagefile, r);
        numRecords++;
        if (slot == maxRecords - 1)
        {
            page.write((char *)pagefile->data, pagefile->page_size);
            init_fixed_len_page(pagefile, page_size, Rec_Size);
            numPages++;
        }
    }
    if (slot != maxRecords - 1) {
        page.write((char *)pagefile->data, pagefile->page_size);
    }
    ftime(&after);
    long finish = after.time * 1000 + after.millitm;

    printf("NUMBER OF RECORDS: %d\n", numRecords);
    printf("NUMBER OF PAGES: %d\n", numPages);
    printf("time : %ld ms\n", finish - now_in_ms);

    page.close();
    csv.close();
    return 0;
}
