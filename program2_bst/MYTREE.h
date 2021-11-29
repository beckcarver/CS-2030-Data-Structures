// Beckham Carver
// COSC 2030
// Used lectures as main resource, used many other sources when developing an AVL tree however as you'll read below
// I had to give up on that endeavor.
#ifndef MYTREE_
#define MYTREE_
#include "cleanword.h"
#include "node.h"

template <class T>

// after spending many hours trying to code my own AVL tree, I got extremely close, ultimately the program lost steam
// when I couldnt fix a bug relating to my findHeight function, I kept getting segmentaion faults when the height > 5
// After bugfixing for two days leading up to the due date, here I am 2 hours before coding a dead simple bst

class BST {
public:
    node<T>*tmp;
    BST() {root = nullptr; tmp = nullptr;}
    ~BST() {root = remove(root);}                       // begin recursion on root to remove all

    int heightR() {return height(root);}                // return the height of the tree
    int heightS(T data) {
        node<T>*n = find(root,data); 
        if(n != nullptr) {                                         // if the data is in tree
            return height(n);                           // return the height of data
        } else {
            return -1;                                  // otherwise return -1 to signify that it is not in tree
        }
    }
    void insert(T data) {root = insert(data, root); size++;}// overloaded insert, so root doesn't have to be public
    void remove(T data) {root = remove(data, root);}    // overloaded remove, so root doesn't have to be public
    node<T>* find(T data) {                                 // overloaded find,   so root doesn't have to be public                             
        return (find(data,root));
    }
    void print() {print(root);}                         // overloaded print,  so root doesn't have to be public
    int getSize() {return size;}
    long int compR(){return comp;}
    
private:
    node<T>* root;                                      // declare root pointer for tree
    long long int size = 0;
    long long int comp = 0;

    int height(node<T>* item){                          // find height from given node
        int h = 0;
        if (item != nullptr){                               // if the node is not empty:
            int l_height = height(item->left);              // recursively read to left
            int r_height = height(item->right);             // recursively read to left
            int max_height = std::max(l_height, r_height);  // return the largest value
            h = max_height + 1;                             // add one
        }
        return h;
    }

    node<T>* remove(node<T>*item){                      // remove a node (and it's children, through recursion)
        if(item == nullptr){                            // if the node is empty, return nullptr to break recursion
            return nullptr;
        } else {                                        // else recursively call for all branches below
            remove(item->left);                     
            remove(item->right);
            delete item;
        }
        return nullptr;
    }

    node<T>* insert(T data, node<T>*&item){
        if(item == nullptr){                            // if the tree is empty:
            item = new node<T>(data);                       // set the root equal to a new node, used constructor in node.h
        } else if(data.compare(item->data) < 0){             // using a function call to do char compares, refer to cleanword.h
            item->left = insert(data, item->left);          // having some experience in ACL2 did help with creating-
        } else if(data.compare(item->data) > 0){              // -boolean functions in this program, yay
            item->right = insert(data, item->right);    // using a function call to do char compares, refer to cleanword.h
        }
        return item;
    }
    node<T>* find(T data, node<T>*item)
    {
        if(item == nullptr){
            comp++;
            return nullptr;
        } else if (data.compare(item->data) < 0){
            comp++;
            return find(data, item->left);
        } else if (data.compare(item->data) > 0){
            comp++;
            return find(data, item->right);
        } else {
            return item;
        }
    }

    node<T>* min(node<T>*item){
        if(item == nullptr){
            return nullptr;
        }
        else if(item->left == nullptr){
            return item;
        }
        else{
            return min(item->left);
        }
    }

    node<T>* max(node<T>*item) {
        if(item == nullptr){                        // helps break recursion
            return nullptr;      
        } else if(item->right == nullptr){
            return item;
        } else {
            return max(item->right);
        }
    }


void print(node<T>* item) {
    if(item == nullptr){
        return;                                     // recursion is weird
    }
    print(item->left);
    std::cout << item->data << " ";
    print(item->right);
    }

};

#endif