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
  node* root;
  node* Add(node* rootAdd, const T& valueAdd) {
    if (rootAdd == nullptr) {
      rootAdd = new node;
      rootAdd->value = valueAdd;
      rootAdd->left = nullptr;
      rootAdd->right = nullptr;
    } else if (rootAdd->value < valueAdd) {
      rootAdd->right = Add(rootAdd->left, valueAdd);
    } else if (rootAdd->value > valueAdd) {
      rootAdd->right = Add(rootAdd->right, valueAdd);
    } else {
      rootAdd->counter++;
    }
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
  int Depth(node* rootDepth) {
    int leftD = 0;
    int rightD = 0;
    if (rootDepth == nullptr) {
      return 0;
    } else {
      leftD = Depth(rootDepth->left);
      rightD = Depth(rootDepth->right);
    }
    if (leftD < rightD) {
      return ++rightD;
    } else {
      return ++leftD;
    }
  }

 public:
  BST() :root(nullptr) {}
  void add(const T& v) {
    root == Add(root, v);
  }
  int search(const T& v) {
    return Search(const T& v);
  }
  int depth() {
    return Depth(root)-1;
  }
};

#endif  // INCLUDE_BST_H_
