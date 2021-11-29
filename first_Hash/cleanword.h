#ifndef CLEANWORD_
#define CLEANWORD_
#include <algorithm> 
#include <cctype>
#include <string>

// Clean function from linked list.

std::string clean(std::string data){
    std::string ns;
    for(int i = 0; i < data.length(); i++){               
        data[i] = std::tolower(data[i]);
        if(isalnum(data[i]) || isdigit(data[i]) || data[i] == '\''){
            ns += data[i];
        }
    }
    return ns;
}

// operator functions to supplement string compares, optimized to return as soon as possible

#endif