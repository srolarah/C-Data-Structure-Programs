/*
Sarah Rolfe
str9wed
hashTable.cpp
*/
#include "hashTable.h"
#include <algorithm>
#include <cmath>

using namespace std;

int algorithm(string word);

hashTable::hashTable(){
  arrayPoint = new string[100000]();
}

hashTable::~hashTable() {
  delete[] arrayPoint;
}

void hashTable::insert(string word) {
  int value = algorithm(word);
  
  int i = 1;
  while(arrayPoint[value].length() != 0){
    value+= algorithmTwo(word)*i;
    i++;
    value = value % 100000;
  }
  arrayPoint[value] = word;
}

int hashTable::algorithmTwo(string word){
  unsigned int i = 0;
    for(int j = 0; j < word.length(); j++) {
    i += word[j];
  }
    unsigned int value = i % 100000;
    return value;
}

int hashTable::algorithm(string word) {
  unsigned int i = 0;
  for(int j = 0; j < word.length(); j++) {
    i += word[j];
  }
  unsigned int value = i % 100000;
  return value;
}

bool hashTable::contains(string word) {
  int value = algorithm(word);

  int i = 1;
  while(arrayPoint[value].length() != 0){
    if(arrayPoint[value] == word){
      return true;
    }
    value = (value + (algorithmTwo(word)*i)) % 100000;
    i++;
  }
  return false;
}
