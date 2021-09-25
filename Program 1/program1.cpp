#include <iostream>
#include "MYLIST.h"

using namespace std;



int main(){

myList<string> test;

test.insert("h");

cout << test.getSize() << endl;
    return 0;
};

