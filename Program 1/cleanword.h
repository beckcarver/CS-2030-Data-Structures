#ifndef CLEANWORD_
#define CLEANWORD_
// code below is adapted from from: 
// https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case
#include <algorithm> 
#include <cctype>
#include <string>

std::string clean(std::string data){
    std::transform(data.begin(), data.end(), data.begin(),
    [](unsigned char c){ return std::tolower(c); });
    return data;
}
#endif
