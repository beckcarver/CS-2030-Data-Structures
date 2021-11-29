//UWYO COSC 2030
//Lab 4
//Written by Danny Radosevich
//8-4-19

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;


//function declarations
string stringReverse(string toReverse);
bool parenCheck(string toCheck);

/*DO NOT CHANGE MAIN OR THE FUNCTION DECLARATIONS*/
int main()
{
  //paren strings
  string paren1 = "(()((((()()()((()(((()()()()(((()(()()()(())()())()()))))()()()))()))()())())())))";
  string paren2 = "()((((((()(((((()((()()()()()(()))))))))()))()(())(())(((((()()(())))(()()())(()))";
  string paren3 = "(()((()(()()(()(((((()()(()()()((((()()(()()))()))))()()())))))()()())()()))())())";
  string paren4 = "(()()(((()()(()(()()(()()()()()()(()(((((((((())())))))()))))()()))()())()()))()))";
  string paren5 = "(())(()(())()(()(()()((())()(()(()()(()()()()())((()((())(())(()))(())())(()())())";
  string paren6 = "()(()(()))((())((()()()(()()((((()(()((()()(())()(())()())()(()()))(((())))())(())";

  string rev1 = "sekopog";
  string rev2 = "racecar";
  string rev3 = "regnolsignirtssiht";
  string rev4 = "wonybnwodsihtevahyllufepohdluohssyuguoy";

  //Ignore thise for now, we will go over vecotrs later
  vector<string> parens;
  parens.push_back(paren1);
  parens.push_back(paren2);
  parens.push_back(paren3);
  parens.push_back(paren4);
  parens.push_back(paren5);
  parens.push_back(paren6);

  vector<string> rever;
  rever.push_back(rev1);
  rever.push_back(rev2);
  rever.push_back(rev3);
  rever.push_back(rev4);
  //call the parenCheck
  for(int i=0; i<6; i++)
  {
    cout<<"Checking string"<<i+1<<endl;
    if(parenCheck(parens.at(i)))
    {
      cout<<"String"<<i+1<<" is good"<<endl<<endl;
    }
    else
    {
      cout<<"String"<<i+1<<" is bad"<<endl<<endl;
    }
  }

  //now to reverse some strings
  for(int i =0; i<4; i++)
  {
    cout<<"Reversing string"<<i+1<<endl;
    cout<<stringReverse(rever.at(i))<<endl<<endl;
  }
}

//This function takes a string and reverses it using a stack
//it returns the reveresed string
string stringReverse(string toReverse)
{
  stack<char> reverse; //declare the stack
  string newString = "";
  for (int i = 0; i < toReverse.length(); i++){
    reverse.push(toReverse.at(i));
  };
  while (!reverse.empty()){
    newString += reverse.top();
    reverse.pop();
  }
  return newString;
}

//this function uses a queue to check if a string of parens is properly matched
bool parenCheck(string toCheck)
{
  queue<char> checker; //declare my queue
  
  for (int i = 0; i < toCheck.length(); i++){
    if (toCheck[i] == '('){ // else push (
      checker.push(toCheck[i]);
    }
    else if (toCheck[i] == ')' && checker.front() == '('){ // if given ), and front = (, pop the (
      checker.pop();
    }
    else {
      cout << "big error lol \n";
    };
  };

  if (checker.size() == 0){
    return true;
  };
  return false; //need a return statement to compile
}
