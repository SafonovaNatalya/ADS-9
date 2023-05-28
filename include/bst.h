// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template<typename T>
class BST {
 private:
  struct node {
    T value;
    int counter;
    node* left;
    node* right;
  };
 int depthTree1 = 0, depthTree = 0;
  node* root;
  node* Add(node* rootAdd, const T& valueAdd) {
    if (rootAdd == nullptr) {
      rootAdd = new node;
      rootAdd->value = valueAdd;
      rootAdd->left = nullptr;
      rootAdd->right = nullptr;
    } else if (rootAdd->value < valueAdd) {
      depthTree++;
      rootAdd->right = Add(rootAdd->left, valueAdd);
    } else if (rootAdd->value > valueAdd) {
      depthTree++;
      rootAdd->right = Add(rootAdd->right, valueAdd);
    } else {
      rootAdd->counter++;
    }
   if (depthTree > depthTree1){
    depthTree1 = depthTree;
   }
   depthTree = 0;
    return rootAdd;
  }
  int Search(node* rootSearch, const T& valueSearch) {
    if (rootSearch == nullptr) {
      return 0;
    } else if (rootSearch->value == valueSearch) {
      return rootSearch->counter;
    } else if (rootSearch->value < valueSearch) {
      return Search(rootSearch->left, valueSearch);
    } else {
      return Search(rootSearch->right, valueSearch);
    }
  }

 public:
  BST() :root(nullptr) {}
  void add(const T& v) {
    root = Add(root, v);
  }
  int search(const T& v) {
    return Search(root, v);
  }
  int depth() {
    return depthTree1;
  }
};

#endif  // INCLUDE_BST_H_
