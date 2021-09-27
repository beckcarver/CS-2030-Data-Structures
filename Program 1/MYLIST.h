// Beckham Carver
// COSC 2030

#ifndef MYLIST_
#define MYLIST_
#include "node.h" 
#include "cleanword.h"
#include <string>

template <class T>
class myList {
    private:
    node<T> * head;
    node<T> * tmp;
    int size;                   
    node<T> * charLoc[123] = {nullptr};         // only uses the last 26 slots, an array of pointers to nodes in the sorted link list
    long int wordCount[123] = {0};              // keeps count of words of each starting letter
    public:                                     
    myList() { head = nullptr; size=0;} 
    ~myList(){
        for (size > 0; size--;){
            tmp = head;
            head = tmp->next;
            delete tmp;
        }
        delete head;
    }

        void Sinsert (T item){
            if(item[0] != 0){                  
                node<T> * newNode = new node<T>(item);  // declaring new node with given item
                if(head == nullptr){
                    head = newNode;                     // if list is empty, insert first
                } else {
                    node<T>* lastNode = head;           // declare a lastNode
                    bool count = false;                 // ensure it lags behind tmp
                    tmp = head;                         // start at the head for sort
                    while(true){
                        if (tmp->data[0] > newNode->data[0]){ // char compare instead of string compare!
                            newNode->next = tmp;
                            lastNode->next = newNode;
                            wordCount[newNode->data[0]]++;
                            if (charLoc[newNode->data[0]] == nullptr){
                                charLoc[newNode->data[0]] = newNode;
                            }
                        break;
                        }
                        if (tmp->next == nullptr){
                            tmp->next = newNode;
                            wordCount[newNode->data[0]]++;
                            if (charLoc[newNode->data[0]] == nullptr){
                                charLoc[newNode->data[0]] = newNode;
                            }
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
        }

        /*bool find(T item){
            if (charLoc[item] != nullptr) { // if linked list contains words of that letter
                tmp = charLoc[item[0]];
                for (int i = 0; i <= wordCount[item[0]]; i++){
                    if(tmp->data){

                    }
                }

            }
            return false;
        }*/

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

        void printHeaders() { // for testing ONLY
            for (int i = 97; i <= 122; i++) {
                if (charLoc[i] != nullptr) {
                    tmp = charLoc[i];
                    std::cout << i - 96 << ":  '" << tmp->data << "'  " << wordCount[i] << std::endl;
                }
                else {
                    std::cout << i - 96 << ":  '0'" << "  " << wordCount[i] << std::endl;
                }
            }
        }
        
        bool isEmpty() {return size ==0;}
        int getSize() {return size;}
};
#endif