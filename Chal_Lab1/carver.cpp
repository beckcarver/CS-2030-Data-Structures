#include <bitset>
#include <iostream>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
    std::string data;
    std::ifstream bin("bin_out.txt");
    while(std::getline(bin, data)){
        std::stringstream sstream(data);
        std::string output;
        while(sstream.good())
        {
            std::bitset<8> bits;
            sstream >> bits;
            char c = char(bits.to_ulong());
            output += c;
        }
        std::cout << output << std::endl;
    };
   return 0;
}

// snagged a lot of my code from 
// https://stackoverflow.com/questions/23344257/convert-a-string-of-binary-into-an-ascii-string-c