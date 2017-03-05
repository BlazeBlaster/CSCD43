#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <sys/timeb.h>
#include <math.h> /* ceil */
#include "library.h"
using namespace std;
#define Num_Columns 6
#define attr_size 10
#define Rec_Size 60
typedef const char *V;
typedef std::vector<V> Record;

int main(int argc, char **argv)
{
  Record *r = NULL;
  ifstream in(argv[1], ifstream::binary);
  char *p;
  char *buf;
  //int numPages = 0;
  int numRecords = 0;

  struct timeb before;
  struct timeb after;

  ftime(&before);
  long now_in_ms = before.time * 1000 + before.millitm;

  buf = (char *)malloc(attr_size);
  int count = 0;
  r = new Record;
  while (in.read(buf, attr_size))
  {
    string p(buf);
    if (!p.empty())
    {
      r->push_back(p.c_str());
    } else {
      continue;
    }
    count++;
    if (count == Num_Columns)
    {
      for (int i = 0; i < r->size(); i++)
      {
        std::cout << r->at(i) << ',';
      }
      r = new Record;
      std::cout << '\n';
      count = 0;
      numRecords++;
    }
  }
  //calc num pages by: ceil(numRecord * size of record / pagesize)
  int numPages = (int)ceil(numRecords * Rec_Size / atof(argv[2]));
  ftime(&after);
  long finish = after.time * 1000 + after.millitm;

  printf("NUMBER OF RECORDS: %d\n", numRecords);
  printf("NUMBER OF PAGES: %d\n", numPages);
  printf("time : %ld ms\n", finish - now_in_ms);
}
