// Beckham Carver
// COSC 2030
// Fun fact: this compiles in Visual Studio, thought I'd check and somehow it does
#ifndef MYLIST_
#define MYLIST_
#include "node.h" 
#include "cleanword.h"

template <class T>
class myList {
    private:
    int size;
    long int compareT = 0;
    long int compareF = 0;
    long int tint = 0;
    node<T> * head;
    node<T> * tmp;            
    node<T> * charLoc[123] = {nullptr};                         // array of pointers to nodes in the (sorted) link list
    long int wordCount[123] = {0};                              // keeps count of words of each starting letter
    public:                                     
    myList() { head = nullptr; size=0;}                         // removed destructor, was breaking program when debugging (not normal use)

        void Sinsert (T item){                                  ////// recieved help with theory of insert from Landon Francis (UVU) no help with code
            if(item[0] != 0){                                   // if the string is not empty, then:           
                node<T> * newNode = new node<T>(item);          // declare new node with given item
                if(head == nullptr){
                    head = newNode;                             // if list is empty, insert first
                } else {
                    node<T>* lastNode = head;                   // declare a lastNode
                    bool count = false;                         // ensure it lags behind tmp
                    tmp = head;                                 // start at the head for sort
                    while(true){
                        if (tmp->data[0] > newNode->data[0]){   // if the next word is greater than the given word
                            if (count == false) {               // if the next word is first in list
                                newNode->next = tmp;
                                head = newNode;
                                wordCount[newNode->data[0]]++;  // increment respective word counter
                                if (charLoc[newNode->data[0]] == nullptr) {
                                    charLoc[newNode->data[0]] = newNode;
                                }
                                break;
                            }                                   // if next word is not first in list
                            newNode->next = tmp;
                            lastNode->next = newNode;
                            wordCount[newNode->data[0]]++;      // increment respective word counter
                            if (charLoc[newNode->data[0]] == nullptr){ // if no header has been made for this letter
                                charLoc[newNode->data[0]] = newNode;   // create new header for letter
                            }
                        break;
                        }
                        if (tmp->next == nullptr){             // if new word is greater than all previous words
                            tmp->next = newNode;
                            wordCount[newNode->data[0]]++;     // increment respective word counter
                            if (charLoc[newNode->data[0]] == nullptr){ // if no header has been made for this letter
                                charLoc[newNode->data[0]] = newNode;   // create new header for letter
                            }
                            break;
                        }
                        if (count == true) {                    // sets the lastNode behind tmp
                            lastNode = lastNode->next;
                        } count = true;                          
                        tmp = tmp->next;                        // iterate to next node
                    }
                }
                size++;
            }
        }

        bool find(T item){
            tint = 0;
            if (charLoc[item[0]] != nullptr) {                  // if linked list contains words of that letter
                tmp = charLoc[item[0]];
                for (int i = 0; i < wordCount[item[0]]; i++){  // only search for words of that letter
                    if(tmp->data[1] == item[1]){                // if second letter is equal
                        tint++;                              // the only instance of string compare in my code
                        if(tmp->data.compare(item) == 0){       // compare entire word to selected in list
                            compareT += tint;
                            return true;
                        }
                    }
                    tmp = tmp->next;                            // increment to next in list
                }
            }
            compareF += tint;
            return false;                                       // if nothing is found in subset, return false
        }

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
        int getT() {return compareT;}
        int getF() {return compareF;}
        bool isEmpty() {return size ==0;}
        int getSize() {return size;}

        // Below function is used only for testing
        void printHeaders() {                                   
            for (int i = 97; i <= 122; i++) {
                if (charLoc[i] != nullptr) {
                    tmp = charLoc[i];
                    std::cout << i - 96 << ":  '" << tmp->data << "'  " << wordCount[i] << std::endl;
                }
                else {
                    std::cout << i - 96 << ":  '0'" << "  " << wordCount[i] << std::endl;
                }
            }
            if (charLoc['\''] != nullptr) {
                tmp = charLoc['\''];
                std::cout <<"apostrophe:  '" << tmp->data << "'  " << wordCount['\''] << std::endl;
            }
            else {
                std::cout <<"aopostrophe:  '0'" << "  " << wordCount['\''] << std::endl;
            }
        }
};
#endif