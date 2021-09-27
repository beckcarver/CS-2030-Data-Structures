#ifndef CLEANWORD_
#define CLEANWORD_
// code below is adapted from from: 
// A: https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case
// B: Michael Snelling helped show me what I was doing wrong, code is written myself
#include <algorithm> 
#include <cctype>
#include <string>
#include <cctype>

std::string clean(std::string data){
    std::transform(data.begin(), data.end(), data.begin(), // A:
    [](unsigned char c){ return std::tolower(c); });
    for(int i = 0; i < data.length(); i++){                // B:
        if(isalnum(data[i]) || isdigit(data[i]) || data[i] == '\''){
        } else{
           data.erase(i,i);
           i++; 
        } 
    }
    return data;
}
#endif
