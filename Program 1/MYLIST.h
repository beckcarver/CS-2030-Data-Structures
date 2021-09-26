// Beckham Carver
// COSC 2030

#ifndef MYLIST_
#define MYLIST_
#include "node.h" 

using std::string;

template <class T>
class myList {
    private:
    node<T> * head;
    node<T> * tmp;
    int size;                   
    node<T> * charLoc[122] = {nullptr};         // only uses the last 26 slots, not allowed to code a -97 into storage
    public:                                     // this is an array of pointers to nodes in the sorted link list
    myList() { head = nullptr; size=0;} 
    ~myList(){
        for (size > 0; size--;){
            tmp = head;
            head = tmp->next;
            delete tmp;
        }
        delete head;
    }
        void insert (T item){
            node<T> * newNode = new node<T>(item); // declaring new node with given item
            if(head == nullptr){
                head = newNode; // if list is empty, insert first
            } else {
                node<T>* lastNode = head; // declare a lastNode
                bool count = false;
                tmp = head; // start at the head
                while(true){
                    if (tmp->data[0] > newNode->data[0]){ // char compare instead of string compare!
                    newNode->next = tmp;
                    lastNode->next = newNode;
                    if (charLoc[newNode->data[0]] == nullptr){
                        charLoc[newNode->data[0]] = newNode;
                    }
                    break;
                    }
                    if (tmp->next == nullptr){
                        tmp->next = newNode;
                        break;
                    }
                    if (count == true) { // sets the lastNode behind tmp
                        lastNode = lastNode->next;
                    }
                    count = true;
                    tmp = tmp->next; // iterate to next node
                }
            }
            size++;
        }

        bool find(T item);

        void removeFront(){
            if (head != nullptr){
                tmp = head;
                head = tmp->next;
                delete tmp;
            }
        }

        T front(){
            tmp = head;
            return tmp->data;
        }

        void print(){
            tmp = head;
            for(int i = 0; i < size; i++){
                std::cout << tmp->data << std::endl;
                tmp = tmp->next;
            }
        }

        void printCharLoc(){ // for testing only
            for (int i = 97; i <= 122; i++){
                std::cout << charLoc[i] << std::endl;
            }
        }
        
        bool isEmpty() {return size ==0;}
        int getSize() { return size;}
};
#endif