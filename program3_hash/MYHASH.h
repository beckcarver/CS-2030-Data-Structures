// Beckham Carver
// COSC 2030
// my program2 code was used for general structure, https://www.geeksforgeeks.org/array-of-linked-list-in-c-cpp/ was used
// for the implementation of the linked list. Stack overflow was used for a few code improvements, hash function was 
// implemented and designed entirely myself.

#ifndef MYTREE_
#define MYTREE_
#define HASHSIZE 133168

// testing with size 50,000 showed a somewhat even spread of words, effeciency plataeus
// at ~75,000 so the hashing function is not completely optimized, but is well adequate.

#include <iostream>
#include <string>
#include "cleanword.h"
#include "node.h"

using std::string;

template <class T>

class HASH
{
public:
    HASH()
    {
        hashArray = new node<T> *[HASHSIZE];
        for (int i = 0; i < HASHSIZE; ++i)
        {
            hashArray[i] = new node<T>;
        }
    }
    ~HASH()
    {
        delete[] hashArray;     // found this method on stack overflow
    }
    int getSize()
    {
        return size;
    }
    int getCompT()
    {
        return t_compares;
    }
    int getCompF()
    {
        return f_compares;
    }
    void insert(T data)
    {
        insert_(data);
    }
    bool find(T data)
    {
        return find_(data);
    }
    void print()
    {
        print_();
    }

private:
    long int size = 0;              // initializes size
    long long int t_compares = 0;   // initializes truecompares
    long long int f_compares = 0;   // intializes false compares
    node<T> **hashArray;            // initializes pointer to array of pointers CREDIT: https://www.geeksforgeeks.org/array-of-linked-list-in-c-cpp/
    node<T> *tmp;

    void insert_(T data) // internal insert function, checks if hashed position is empty, then searches for duplicate, and then empty spot
    {
        int index = hasher2(data);
        if (hashArray[index]->next == nullptr)
        {
            size++;
            hashArray[index]->data = data;
            hashArray[index]->next = new node<T>;
        }
        else
        {
            bool duplicate = false;
            tmp = hashArray[index]->next;
            while (tmp->next != nullptr)
            {
                if (tmp->data.compare(data) == 0)
                {
                    duplicate = true;
                    break;
                }
                tmp = tmp->next;
            }
            if (duplicate == false)
            {
                size++;
                tmp->data = data;
                tmp->next = new node<T>;
            }
            // if duplicate == true, do nothing, duplicate was found
        }
    }

    bool find_(T data) // internal find function, checks hash position, then all following positions
    {
        int tmp_compares = 0;
        int index = hasher2(data);
        tmp = hashArray[index];
        while (true)
        {
            tmp_compares++;
            if (tmp->data.compare(data) == 0)
            {
                t_compares += tmp_compares;
                return true;
            }
            if (tmp->next == nullptr)
            {
                f_compares += tmp_compares;
                return false;
            }
            tmp = tmp->next;
        }
        return false; // this should never get to this point, ever, ever, ever, ever.
    }

    // my original goal with this hash function was to use division to preserve the ordering of the characters
    // when hashing, I made sure to divide by the first character to prevent x / 0
    // adding to the numerator improved speed and prevents 0 / x
    // multiplying the numerator by i improved speed dramatically, this further weights the size of strings
    // multuplying the numerator by 5 made a consistent, marginal improvement to speed

    int hasher2(string toHash)
    {
        double tmp = 0;

        for (int i = 1; i < toHash.length(); i++)
        {
            tmp += (i * i * i * 5 * toHash[i] + 1000 / toHash[i - 1]); 
        }
        int val = int(tmp);
        return val % HASHSIZE;
    }

    void print_() // test print function
    {
        for (int i = 0; i < 50; i++)
        {
            tmp = hashArray[i];
            std::cout << "~~~~~~~~~~~~new list:\n"
                      << tmp->data << std::endl;
            while (tmp->next != nullptr)
            {
                tmp = tmp->next;
                std::cout << tmp->data << std::endl;
            }
        }
    }
    /*
 // this is my original hashing function from the lab.
 // this hasher is somewhat slow, but has few collisions and produces hilarious collisions at that!

    int hasher(string toHash)  
    {
        long long int val = 0;
        srand(1); // ensures rand() starts with the same seed
        for (int i = 0; i < toHash.length() && i < 5; i++)
        { 
            srand(toHash[i] + rand()); // sets seed to hash value plus a random number from old seed
            val += rand();             // adds to value with the newly seeded random number
        }
        val += toHash.back();
        val *= toHash.length();
        //if(size % 12 == 0){std::cout << val << std::endl;} // test code for viewing SOME hashes
        return val % HASHSIZE;
    }

*/
};

#endif
