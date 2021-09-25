#ifndef NODE_
#define NODE_

template<class T> 

class node {
  public:
  T data;
  node<T> * next; 
  node<T> * last; 
  node() { last = nullptr; next = nullptr;};
  node(T item) {
      data = item;
      next = nullptr;
  }
};
#endif
