#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;
#include <fstream>

#include "library.h"



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
    int page_id;
    int num_slots;
    int offset;
} DirectoryPage;

/**
 * Initalize a heapfile to use the file and page size given.
 */
void init_heapfile(Heapfile *heapfile, int page_size, FILE *file)
{
    heapfile->page_size = page_size;
    heapfile->file_ptr = file;

    Page *directory = new Page;
    init_fixed_len_page(directory,page_size,30); // ?
    

}

PageID alloc_page(Heapfile *heapfile)
{
    Page *pagefile = new Page;


}

class RecordIterator
{
  public:
    RecordIterator(Heapfile *heapfile);
    Record next();
    bool hasNext();
};