#include <iostream>
#include "MYLIST.h"
#include <string>

using std::string;

int main(){

    myList<string> test;

    test.insert("h");
    test.insert("hh");
    test.insert("hhh");
    test.insert("hhhh");

    std::cout << test.getSize() << std::endl;

    return 0;

}

