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
  int mdepthTree = 0, depthTree = 0;
  node* root;
  node* Add(node* root, const T& value) {
    if (!root) {
     root = new node;
     root->value = value;
     root->counter = 1;
     root->right = root->left = nullptr;
     return root;
    } else if (root->value > value) {
      depthTree++;
      root->left = Add(root->left, value);
    } else if (root->value < value) {
      depthTree++;
      root->right = Add(root->right, value);
    } else {
      root->counter++;
    }
  if (depthTree > mdepthTree) {
    mdepthTree = depthTree;
  }
  depthTree = 0;
    return root;
  }
  int Search(node* root, const T& value) {
   int result = 0;
   if (root->value == value) {
    result = root->counter;
   }
   if (root->value > value) {
    result = Search(root->left, value);
   }
   if (root->value < value) {
    result = Search(root->right, value);
   }
   return result;
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
    return mdepthTree;
  }
};

#endif  // INCLUDE_BST_H_
