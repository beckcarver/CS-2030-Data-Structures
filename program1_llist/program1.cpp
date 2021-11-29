#include <iostream>
#include <fstream>
#include <vector> // using a vector to store misspelled words
#include <iomanip>
#include "MYLIST.h"
#include "timer.h"

using std::string;
using std::endl;
using std::cout;
using std::vector;

int main(){
    string word;
    long int correct = 0;
    long int incorrect = 0;
    long int skip = 0;
    vector<string> misspelled;
    myList<string> dictList;
    Timer timer;

    std::ifstream dict("dict.txt");
    if(dict.is_open()){
        while(dict >> word){ 
            dictList.Sinsert(clean(word));
        }
        dict.close();
    }

    cout << "dictionary size is " << dictList.getSize() << endl;

    timer.Start();

    std::ifstream book("book.txt");
    if(book.is_open()){
        while(book >> word){
            word = clean(word);
            if (word[0] == 0){
                // dont search
            } else if(isdigit(word[0]) || word[0] == '\''){
                skip++;
            } else if(dictList.find(word)){
                correct++;
            } else{
                misspelled.push_back(word); // taking size of vector to count incorrect words
                incorrect++;
            }
        }
    }
    
    timer.Stop();

    cout << "Done checking and these are the results " << endl;
    cout << "finished in time: " << std::setprecision(2) << timer.Time() << endl;
    cout << "There are " << correct << " words found in the dictionary" << endl;
    cout << "     " << dictList.getT() << " compares. Average: "<< (dictList.getT()/correct) << endl;

    cout << "\nThere are: " << incorrect << " words NOT found in the dictionary\n";
    cout << "     " << dictList.getF() << " compares. Average: "<< (dictList.getF()/incorrect) << endl;
    cout << "There are " << skip << " words not checked." << endl;

    return 0;
}
