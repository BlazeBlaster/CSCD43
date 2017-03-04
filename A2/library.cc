#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef const char *V;
typedef std::vector<V> Record;
typedef unsigned char byte;
const int attr_size = 10;
typedef struct
{
    void *data;
    int page_size;
    int slot_size;
} Page;

/**
 * Compute the number of bytes required to serialize record
 */
int fixed_len_sizeof(Record *record)
{

    int len = record->size();
    int total = 0;
    const char *field;
    for (int i = 0; i < len; i++)
    {
        field = (*record)[i];
        total += strlen(field);
    }
    return total;
}

/**
 * Serialize the record to a byte array to be stored in buf.
 */
void fixed_len_write(Record *record, void *buf)
{
    byte *buff = (byte *)buf;
    int len = record->size();
    int fieldlen;
    int total = 0;
    const char *field;
    int offset = 0;
    for (int i = 0; i < len; i++)
    {
        field = (*record)[i];
        printf("???", field);
        fieldlen = strlen(field);
        memcpy(buff + offset, field, fieldlen);
        offset += fieldlen;
    }
}

/**
 * Deserializes `size` bytes from the buffer, `buf`, and
 * stores the record in `record`.
 */
void fixed_len_read(void *buf, int size, Record *record)
{
    char *buff = (char *)buf;
    char *a = (char *)malloc(size);
    memcpy(a, buff, size);
    record->push_back((V)a);
}

/**
 * Initializes a page using the given slot size
 */
void init_fixed_len_page(Page *page, int page_size, int slot_size)
{
    page->data = malloc(page_size);
    memset(page->data, '\0', page_size);
    page->page_size = page_size;
    page->slot_size = slot_size;
    return;
}

/**
 * Calculates the maximal number of records that fit in a page
 */
int fixed_len_page_capacity(Page *page)
{
    return (page->page_size / page->slot_size);
}

/**
 * Calculate the free space (number of free slots) in the page
 */
int fixed_len_page_freeslots(Page *page)
{
    char *iterator = (char *)page->data;
    int count = 0;
    while (iterator != NULL)
    {
        count++;
        iterator += page->slot_size;
    }
    return (page->page_size / page->slot_size) - count;
}

/**
 * Add a record to the page
 * Returns:
 *   record slot offset if successful,
 *   -1 if unsuccessful (page full)
 */
int add_fixed_len_page(Page *page, Record *r)
{
    char *iterator = (char *)page->data;
    int slotcount = 0;
    int count = 0;
    while (count <= (page->page_size / page->slot_size))
    {
        if (*iterator == '\0')
        {
            break;
        }
        count++;
        iterator += (page->slot_size);
    }
    if (count == (page->page_size / page->slot_size))
    {
        return -1;
    }
    else
    {
        int size = r->size();
        int total = 0;
        for (int i = 0; i < size; i++)
        {
            int len = strlen((*r)[i]);
            if ((total + len) <= page->slot_size)
            {
                memcpy(iterator, (*r)[i], attr_size);
                iterator += attr_size;
                total += attr_size;
            }
            else
            {
                break;
            }
        }
        return count;
    }
}

/**
 * Write a record into a given slot.
 */
void write_fixed_len_page(Page *page, int slot, Record *r)
{
    char *iterator = (char *)page->data;
    int count = 0;
    while (iterator != NULL)
    {
        count++;
        iterator += page->slot_size;
        if (count == slot)
        {
            break;
        }
    }
    fixed_len_write(r, iterator);
}

/**
 * Read a record from the page from a given slot.
 */
void read_fixed_len_page(Page *page, int slot, Record *r)
{
    char *iterator = (char *)page->data;
    int count = 0;
    while (iterator != NULL)
    {
        count++;
        iterator += page->slot_size;
        if (count == slot)
        {
            break;
        }
    }
    fixed_len_read(iterator, page->slot_size, r);
}