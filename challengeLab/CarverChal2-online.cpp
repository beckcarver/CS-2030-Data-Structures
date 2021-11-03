// Beckham Carver
// Challenge lab 2
// code is heavily copied from https://stackoverflow.com/questions/59013166/c-morse-to-english


#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

// http://www.csgnetwork.com/morsecodechrtbl.html
map< char, string > ascii_to_morse =
{
{'A',".-"},
{'B',"-..."},
{'C',"-.-."},
{'D',"-.."},
{'E',"."},
{'F',"..-."},
{'G',"--."},
{'H',"...."},
{'I',".."},
{'J',".---"},
{'K',"-.-"},
{'L',".-.."},
{'M',"--"},
{'N',"-."},
{'O',"---"},
{'P',".--."},
{'Q',"--.-"},
{'R',".-."},
{'S',"..."},
{'T',"-"},
{'U',"..-"},
{'V',"...-"},
{'W',".--"},
{'X',"-..-"},
{'Y',"-.--"},
{'Z',"--.."},
{'0',"-----"},
{'1',".----"},
{'2',"..---"},
{'3',"...--"},
{'4',"....-"},
{'5',"....."},
{'6',"-...."},
{'7',"--..."},
{'8',"---.."},
{'9',"----."},
{'.',".-.-.-"},
{',',"--..--"},
{'?',"..--.."},
{'=',"-...-"},
};

map< string, char > morse_to_ascii;

int main()
{
  // build the reversed map
  for (auto kv : ascii_to_morse)
    morse_to_ascii[kv.second] = kv.first;

  // morse to ascii test
  {
    ifstream is{ "morse.txt" };
    if (!is)
      return -1;

    // morse to ascii
    string m;
    while (is >> m)
      cout << morse_to_ascii[m] << ' ';
    
  }
  cout << endl;
}