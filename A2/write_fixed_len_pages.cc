#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
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
    printf("HERE");

    size_t page_size = atoi(argv[3]);
    ifstream csv;
    csv.open(argv[1]);

    ofstream page;
    page.open(argv[2]);
    printf("HERE");

    Page *pagefile = new Page;
    init_fixed_len_page(pagefile, page_size, Rec_Size);

    printf("fixed len page ?\n");
    int maxRecords = fixed_len_page_capacity(pagefile);
    printf("%d\n", maxRecords);
    string line;
    string attribute;

    int numPages = 0;
    int numRecords = 0;
    //cout << line;
    int i = 0;
    while (getline(csv, line))
    {
        Record *r = NULL;
        r = new Record;
        istringstream field(line);
        while (getline(field, attribute, ','))
        {               
            r->push_back(attribute.c_str());
        }

        i++;

        int slot = add_fixed_len_page(pagefile, r);
        numRecords++;
        cout << "slot is " << slot;
        if (slot == maxRecords - 1)
        {
            printf("SLOT EQUALS RECORDS");
            page << pagefile->data;
            init_fixed_len_page(pagefile, page_size, Rec_Size);
            numPages++;
        }
    }

    // printf("NUMBER OF RECORDS: %d\n", numRecords);
    // printf("NUMBER OF PAGES: %d\n", numPages);

    page.close();
    csv.close();
    return 0;
}