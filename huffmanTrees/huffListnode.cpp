#include "huffListnode.h"
#include <string>

using namespace std;

huffListnode::huffListnode(){
  value = "";
  left = NULL;
  right = NULL;
}

huffListnode::huffListnode(string x){
  value = x;
  left = NULL;
  right = NULL;
}

huffListnode::~huffListnode(){
}
