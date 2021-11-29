#ifndef CLEANWORD_
#define CLEANWORD_
#include <algorithm> 
#include <cctype>
#include <string>
#include <cctype>

// Michael Snelling helped show me what I was doing wrong, code is written myself

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
#endif
