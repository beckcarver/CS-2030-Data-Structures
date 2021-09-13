#ifndef NODE_
#define NODE_

template<class T> 

class node {
  public:
  T data;
  node<T> * next; 
 // node<T> * last; 
  node() { next = nullptr;}
 // node() { last = nullptr;}
  node(T item) {
      data = item;
      next = nullptr;
  }
};
#endif