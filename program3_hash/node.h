#ifndef NODE_
#define NODE_

// used https://gist.github.com/Harish-R/097688ac7f48bcbadfa5 as reference

template<class T> 

class node {
  public:;
  T data;      
  node<T> * next; 
  node() {next = nullptr;}; // constructs empty node
  node(T item) { // constructs with T data
      data = item;
      next = nullptr;
  }
};
#endif