/*
Sarah Rolfe
str9wed
hashTable.h
 */
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>

using namespace std;

bool checkprime(unsigned int p);
int getNextPrime(unsigned int n);

class hashTable{
  
 public:
  hashTable();
  ~hashTable();
  void insert(string word);
  int algorithm(string word);
  int algorithmTwo(string word);
  bool contains(string word);

 private:
  string* arrayPoint;
};
#endif
