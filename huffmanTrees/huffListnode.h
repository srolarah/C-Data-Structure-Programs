#ifndef HUFFLISTNODE_H
#define HUFFLISTNODE_H
#include <string>
using namespace std;

class huffListnode{
 public:
  huffListnode();
  huffListnode(string x);
  ~huffListnode();

  string value;
  huffListnode* left;
  huffListnode* right;
};

#endif
