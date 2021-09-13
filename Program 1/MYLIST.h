// Beckham Carver
// COSC 2030

#ifndef MYLIST_
#define MYLIST_
#include "node.h" 
template <class T>
class myList {
 private:
   node<T> * head;
   node<T> * tmp;
   int size;
public:
    myList()
      { head = nullptr; size=0;} 
   ~myList(){                       // I don't know if this is faster, but I figured it only takes a second to give the destructor
       for (size > 0; size--;){     // its own set of delete code instead of calling remove repeatedly, less memory travel... i think.
           tmp = head;
           head = tmp->next;
           delete tmp;
       }
       delete head;
   };
    void insert (T item);
    void remove(){
        if (head != nullptr){
        tmp = head;
        head = tmp->next;
        delete tmp;
        }
    };
    T front();
    void print();
    bool find(T item);
    bool isEmpty() {
       return size ==0;
    }
    int getSize() { return size;}
};
#endif