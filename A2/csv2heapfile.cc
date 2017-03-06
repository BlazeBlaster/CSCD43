#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>

#include "library.h"

using namespace std;

typedef int PageID;

typedef struct
{
    FILE *file_ptr;
    int page_size;
    PageID nextFree;
} Heapfile;

typedef struct
{
    int page_id;
    int slot;
} RecordID;

typedef struct {
    int page_id; //this "page" id
    int num_slots; //number of slots in this page
    int offset; // the offset of this page
} DirectoryPage;

typedef struct {
    int offset; //where this directory is
    int next; //where the next directory is
} DirectoryInfo;

/**
 * Initalize a heapfile to use the file and page size given.
 */
void init_heapfile(Heapfile *heapfile, int page_size, FILE *file)
{
    printf("???\n");
    heapfile->page_size = page_size;
    heapfile->file_ptr = file;


    FILE *f = file;
    void *c = malloc(page_size);
    printf("KENNY WTF\n");
    int empty = fread (c, page_size, 1, f);
    if (!empty) {
        printf("EMPTY?\n");
        Page *directory = new Page;
        init_fixed_len_page(directory,page_size,12); // ?
        DirectoryInfo *d = new DirectoryInfo;
        d->offset = 0;
        d->next = -1;

        memcpy(directory->data,d,page_size);
        /// ?????
        fwrite(directory->data,page_size,1,f);
    } else {
        Page *directory = new Page;
        ///????????
        
    }

}


int main(int argc, char **argv) {
    Heapfile *h = new Heapfile;
    FILE *f = fopen("heapfile", "r+");
    init_heapfile(h, 1000, f);
    return 1;
}

