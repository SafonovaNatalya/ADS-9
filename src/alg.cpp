// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* fname) {
BST<std::string> bst;
  std::ifstream file(fname);
  std::string word;
  while (!file.eof()) {
    char k = file.get();
    if (k >= 65 && k <= 90) {
      k+=32;
      word+=k;
      continue;
    }
    if (k >= 97 && k <= 122) {
      word += k;
    } else {
      if (!word.empty()) {
        bst.add(word);
      }
      word.clear();
    }
  }
  bst.add(word);
  file.close();
  return bst;
}
