// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* fname) {
BST<std::string> bst;
  std::ifstream file(fname);
  std::string word = "";
  if (!file.is_open()) {
    throw std::string("Error! Can not open file!");
  }
  while (!file.eof()) {
    while (true) {
      char k = file.get();
      if ((k >= 97 && k <= 122) || (k >= 65 && k <= 90)) {
        word += tolower(k);
      } else {
        break;
      }
    }
    bst.add(word);
  }
  return bst;
}
