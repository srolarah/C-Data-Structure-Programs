// This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "huffListnode.h"
using namespace std;

void insert(huffListnode* h, string pre, string cha);
string decode(huffListnode* h, string d);
void printTree(huffListnode* h);

// main(): we want to use parameters
int main (int argc, char** argv) {
  
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    //create hufflistnode
    huffListnode* huff = new huffListnode();

    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
	
        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
	
        // do something with the prefix code
	insert(huff, prefix, character);
	
        //cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl; *commented out
    }

    //printTree(huff);

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
	cout << decode(huff, bits);
        // add it to the stringstream
        sstm << bits;
    }

    cout << "" << endl;

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl; *commented out
    // close the file before exiting
    file.close();

    return 0;
}

/*
insert(node, prefix, char):
    if prefix is empty string:
        node->value = char
    else if prefix[0] = '0':
        if node->left == NULL:
            node->left = new node
	insert(node->left, prefix.substring(1, prefix.length), char)
    else if prefix[0] = '1':
        if node->right = NULL:
	    node->right = new node
	insert(node->right, prefix.substring(1, prefix.length), char)
*/

void insert(huffListnode* h, string pre, string cha){
  if (pre.length() == 0){
    h->value = cha;
  }else if(pre[0] == '0'){
    if(h->left == NULL){
      h->left = new huffListnode();
    }
    insert(h->left, pre.substr(1), cha);
  }else if(pre[0] == '1'){
    if(h->right == NULL){
      h->right = new huffListnode();
    }
    insert(h->right, pre.substr(1), cha);
  }
}


/* 
  string s = pre.substr(count, 1);
  
  if (count == pre.length() - 1){
    if (s == "0"){
      if(h->left == NULL)
	h->left = new huffListnode(value);
    }else if (s == "1"){
      if(h->right == NULL)
	h->right = new huffListnode(value);
    }
  }else if(count < pre.length() - 1){
    if (s == "0"){
      if(h->left == NULL){
	h->left = new huffListnode();
	count++;
	insert(h->left, pre, count, value);
      }
    }else if (s == "1"){
      if(h->right == NULL){
	h->right = new huffListnode();
	count++;
	insert(h->right, pre, count, value);
      }
    } 
  }
  

}
  */


string decode(huffListnode* h, string d){
  if (d.length() == 0){
    return h->value;
  }else if(d[0] == '0'){
    return decode(h->left, d.substr(1));
  }else if(d[0] == '1'){
    return decode(h->right, d.substr(1));
  }
  return "";

  /*
  string s = d.substr(count, 1);

  if (count < d.length()- 1){
    if (s == "0"){
      count++;
      decode(h->left, d, count);
    }else if (s == "1"){
      count++;
      decode(h->right, d, count);
    }
  }
  
  return h->value; // count == d.length() - 1
  */
  
}

/*
void printTree(huffListnode* h){
  if(h->right != NULL || h->left != NULL){
    if (h->right != NULL)
      printTree(h->right);
    if (h->left != NULL)
      printTree(h->left);
  }
  cout << h->value << endl;
}
*/

