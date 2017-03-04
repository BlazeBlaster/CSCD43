#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
typedef const char* V;
typedef std::vector<V> Record;

std::string str;

int main()
{
  std::string str;
  Record r;
  ifstream in ("file.csv");
  char * p;
  //go through csv line by line
  while (std::getline(in, str)) {
    //reset Record r for each line
    r.clear();
    std::istringstream ss(str);
    std::string token;
    //token is all the comma split tokens
    while(std::getline(ss, token, ',')) {
      //create new char* to add to Record r
      p = new char[token.size() + 1];
      std::copy(token.begin(), token.end(), p);
      p[token.size()] = '\0';
      r.push_back(p);
    }
    /* Uncomment to see print values with tabs instead of commas
    for (int i =0; i < r.size(); i++){
      std::cout << r[i] << '\t';
    }
    std::cout << '\n';
    */

    //INSERT: method to write r to a page file

  }
}
