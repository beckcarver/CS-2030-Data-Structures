#include <iostream>
#include "MYLIST.h"
#include <string>

using std::string;

int main(){

    myList<string> test;

    string hecka = "hHHxch4h";

    test.Sinsert(clean("A"));
    test.Sinsert(clean("z"));
    test.Sinsert(clean("c"));
    test.Sinsert(clean("d"));
    test.Sinsert(clean("zZz"));
    test.Sinsert(clean("HhH"));
    test.Sinsert(clean("x"));
    test.Sinsert(clean(hecka));
    test.Sinsert(clean("Z"));
    test.Sinsert(clean("a 5"));
    test.Sinsert(clean(""));

    std::cout << "size is: " << test.getSize() << std::endl;
    std::cout << "front is: " << test.front() << std::endl;

    std::cout << "List is: \n";
    test.print();
    test.printHeaders();

    std::cout << "cleaned version of '" << hecka <<"' is: " << clean(hecka) << std::endl;

    std::cout << "is 'z' in the list: " << test.find("z") << std::endl;
    std::cout << "is 'what' in the list: " << test.find("what") << std::endl;
    std::cout << "is '" << hecka <<"' in the list: " << test.find(clean(hecka)) << std::endl;

    return 0;

}

