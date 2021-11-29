#ifndef NODE_
#define NODE_

// used https://gist.github.com/Harish-R/097688ac7f48bcbadfa5 as reference

template<class T> 

class node {
  public:;
  int height; // tried computing height in the tree, adding height to node simplified the code
  T data;      
  node<T> * left; 
  node<T> * right; 
  node() {left = nullptr; right = nullptr;}; // constructs empty node
  node(T item) { // constructs with T data
      data = item;
      left = nullptr;
      right = nullptr;
  }
};
#endif