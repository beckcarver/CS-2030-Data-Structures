#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector> // using a vector to store misspelled words
#include <iterator>
#include "MYHASH.h"
#include "timer.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string word;
    long int correct = 0;
    long int incorrect = 0;
    long int skip = 0;
    vector<string> misspelled;
    HASH<string> dictList;
    Timer timer;

    std::ifstream dict("dict.txt");
    if (dict.is_open())
    {
        while (dict >> word)
        {
            dictList.insert(clean(word));
        }
        dict.close();
    }

    cout << "dictionary size is " << dictList.getSize() << endl;

    timer.Start();

    std::ifstream book("book.txt");
    if (book.is_open())
    {
        while (book >> word)
        {
            word = clean(word);
            if (word[0] == 0)
            {
                // dont search                          <--- if you add 'break;' here, it completely destroys the program
            }
            else if (isdigit(word[0]) || word[0] == '\'')
            {
                skip++;
            }
            else if (dictList.find(word) == true)
            {
                correct++;
            }
            else
            {
                misspelled.push_back(word); // taking size of vector to count incorrect words
                incorrect++;
            }
        }
    }

    timer.Stop();

    // output vector to file function https://stackoverflow.com/questions/6406356/how-to-write-vector-values-to-a-file
    // control+v is the most powerful tool of a programmer, also it makes me happy to see such dense and powerful code.

    std::ofstream output_file("misspelled.txt");
    std::ostream_iterator<std::string> output_iterator(output_file, "\n");
    std::copy(misspelled.begin(), misspelled.end(), output_iterator);

    long double totalW = (correct + incorrect);   // total words
    long double truC = dictList.getCompT();
    long double falC = dictList.getCompF();

    cout << "Done checking and these are the results " << endl;
    cout << "finished in time: " << std::setprecision(2) << timer.Time() << endl;
    cout << "finished in Milliseconds Time: " << std::setprecision(10) << timer.TimeMS() << ".00" << endl;
    cout << "There are " << correct << " words found in the dictionary" << endl;
    cout << "     " << std::setprecision(8) << truC << " compares. Average: " << std::setprecision(2) << (truC / correct) << endl;
    cout << "\nThere are: " << incorrect << " words NOT found in the dictionary\n";
    cout << "     " << std::setprecision(6) << falC << " compares. Average: " << std::setprecision(2) << (falC / incorrect) << endl;
    cout << "There are " << skip << " words not checked." << endl << endl;

    //dictList.print();

    return 0;
}