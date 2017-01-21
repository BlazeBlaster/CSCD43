#include "library.h"
#include <stdlib.h>
#include <stdio.h>

int helper()
{
    printf("Usage: get_histogram <filename> <block size>\n");
    printf("<filename>: a filename (that does exist) to be read in the current directory\n");
    printf("<block size>: (A number > 0) representing the block size to emulate\n");
    return 1;
}
/**
 * file_ptr : the file pointer, ready to be read from.
 * hist: an array to hold 26 long integers.  hist[0] is the
 *       number of 'A', and hist[1] is the number of 'B', etc.
 * block_size: the buffer size to be used.
 * milliseconds: time it took to complete the file scan
 * total_bytes_read: the amount data in bytes read
 *
 * returns: -1 if there is an error.
 */
int get_histogram(FILE *file_ptr, long hist[], int block_size, long *milliseconds, long *total_bytes_read)
{
    char *buffer;
    /* Initial memory allocation */
    buffer = (char *)malloc(block_size);
    int counter = 0;
    int index;
    long cur_time = getMicrotime();
    while (counter < (*total_bytes_read / (long)block_size)) {
        fread(buffer, 1, block_size, file_ptr);
        for (index = 0; index < block_size; index++) {
            hist[buffer[index] - 'A'] +=1;
        }
        counter++;
    }    
    fclose(file_ptr);
    long end_time = getMicrotime();
    *milliseconds = end_time - cur_time;
    return 0;

}

int main(int argc, char *argv[])
{
    long hist[26];
    long microseconds;
    long filelen;
    for (int i = 0; i < 26; i++) {
        hist[i] = 0;
    }

    if (argc != 3)
    {
        helper();
        return 1;
    }
    char *filename = argv[1];
    long blockSize = strtol(argv[2], NULL, 10);

    if (!blockSize)
    {
        //blockSize is 0 or NaN
        helper();
        return 1;
    }

    FILE *file_ptr = fopen(filename, "r");
    fseek(file_ptr, 0, SEEK_END);
    filelen = ftell(file_ptr);
    fclose(file_ptr);
    file_ptr = fopen(filename, "r");

   int ret = get_histogram(file_ptr, hist, blockSize, &microseconds, &filelen);

    printf("Computed the histogram in %ld microseconds.\n", microseconds);
    for (int i = 0; i < 26; i++)
    {
        printf("%c : %ld\n", 'A' + i, hist[i]);
    }
    printf("Data rate: %f Bps\n", ((double)filelen / microseconds) * 1000000);
}