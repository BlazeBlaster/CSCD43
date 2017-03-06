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
    fseek(f, 0, SEEK_SET);
    int empty = fread (c, page_size, 1, f);
    if (!empty) {
        printf("EMPTY?\n");
        Page *directory = new Page;
        init_fixed_len_page(directory,page_size,12); // ?
        DirectoryInfo *d = new DirectoryInfo;
        d->offset = 0;
        d->next = -1;
        printf("d is ? %d\n", (d->offset));
        memcpy((int *)directory->data,&(d->offset),1);
        memcpy((int *)directory->data + 1,&(d->next), sizeof(int));
        int *a = (int *)malloc(1);
        memcpy(a,(int *)(directory->data) + 1,sizeof(int));
        /// ?????
        fwrite(directory->data,page_size,1,f);
    } else {
        return;
        // ??? 
    }

}

PageID alloc_page(Heapfile *heapfile) {
    FILE *f = heapfile->file_ptr;
    int page_size = heapfile->page_size;
    fseek(f, 0, SEEK_SET);
    int *c = (int *)malloc(1);
    int *d = (int *)malloc(1);
    int empty = fread(c, sizeof(int), 1, f);
    int next = fread(d, sizeof(int), 1, f);
    if (!empty) {
        printf("Houston we have a problem");
    } else {
        printf("the offset is %d\n", *c);
        printf("The next page is %d\n", *d);
        
        int *cur_page = (int *)malloc(1);
        int *cur_num_slots = (int *) malloc(1);
        int *cur_offset = (int *)malloc(1);
        int offset = 0;
        while (!(fread(cur_page, sizeof(int), 1, f) || fread(cur_num_slots, sizeof(int), 1, f) || fread(cur_offset, sizeof(int), 1, f))) {
            printf("cur page is %d, cur_num_slots is %d, cur_offset is %d\n", *cur_page, *cur_num_slots, *cur_offset);
            offset++;
        }
        printf("we're done traversing and the first page is free at offset %d\n", offset);
        printf("the pointer is currently at %d\n, the beginning is %d\n", SEEK_CUR, SEEK_SET);
    }
}


int main(int argc, char **argv) {
    Heapfile *h = new Heapfile;
    FILE *f = fopen("heapfile", "rb+");
    init_heapfile(h, 1000, f);
    alloc_page(h);
    return 1;
}

