// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::ifstream file(filename);
  std::string line, text, push;
  while (std::getline(file, line)) {
    text = text + line + " ";
  }
  for (auto k : text) {
    if (isalpha(k)) {
      k = tolower(k);
      push += k;
    } else {
      tree.add(push);
      push = "";
    }
  }
  file.close();
  return tree;
}
