#include <iostream>
#include "MYLIST.h"
#include <string>

using std::string;

int main(){

    myList<string> test;

    test.insert("a");
    test.insert("c");
    test.insert("d");
    test.insert("z");
    test.insert("hhh");
    test.insert("x");
    test.insert("hhhhhh");
    test.insert("h");

    std::cout << "size is: " << test.getSize() << std::endl;
    std::cout << "front is: " << test.front() << std::endl;

    std::cout << "List is: \n";
    test.print();
    test.printCharLoc();

    return 0;

}

