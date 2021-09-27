#include <iostream>
#include "MYLIST.h"
#include <string>

using std::string;

int main(){

    myList<string> test;

    test.Sinsert(clean("A"));
    test.Sinsert(clean("z"));
    test.Sinsert(clean("c"));
    test.Sinsert(clean("d"));
    test.Sinsert(clean("zZz"));
    test.Sinsert(clean("HhH"));
    test.Sinsert(clean("x"));
    test.Sinsert(clean("hHHxchhh"));
    test.Sinsert(clean("Z"));
    test.Sinsert(clean(""));

    std::cout << "size is: " << test.getSize() << std::endl;
    std::cout << "front is: " << test.front() << std::endl;

    std::cout << "List is: \n";
    test.print();
    test.printHeaders();

    return 0;

}

