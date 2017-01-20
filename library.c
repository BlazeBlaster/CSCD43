#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

//courtesy of github: https://gist.github.com/sevko/d23646ba07c77c15fde9
long getMicrotime(){
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}
/**
 * populate a random array (which is already
 * allocated with enough memory to hold n bytes.
 */
void random_array(char *array, long bytes)
{
    long now =  getMicrotime();
    srand(now);
    long index;
    char c;
    for (index = 0; index < bytes; index++)
    {
        c = 'A' + (rand() % 26);
        array[index] = c;
    }
}
