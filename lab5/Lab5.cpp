// Danny Radosevich
// Lab 5
// Written for UWYO COSC 2030
// must be compiled with c++ 11

#include "card.h"
#include <vector>
#include <string>
#include <deque>
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <cstdlib>

using namespace std;

bool parenCheck(string toCheck);
string stringReverse(string toReverse);
void buildAndDeal();

int myRand(int i)
{
  return rand()%i;  
}


/*DO NOT CHANGE MAIN OR THE FUNCTION DECLARATIONS*/

int main()
{
  //paren strings
  string paren1 = "(()((((()()()((()(((()()()()(((()(()()()(())()())()()))))()()()))()))()())())())))";
  string paren2 = "()((((((()(((((()((()()()()()(()))))))))()))()(())(())(((((()()(())))(()()())(()))";
  string paren3 = "(()((()(()()(()(((((()()(()()()((((()()(()()))()))))()()())))))()()())()()))())())";
  string paren4 = "(()()(((()()(()(()()(()()()()()()(()(((((((((())())))))()))))()()))()())()()))()))";
  string paren5 = "((())";
  string paren6 = ")))(((";

  //strings to reverse
  string rev1 = "sekopog";
  string rev2 = "racecar";
  string rev3 = "regnolsignirtssiht";
  string rev4 = "wonybnwodsihtevahyllufepohdluohssyuguoy";

  //Putting the strings in the vector
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


  //this is the function call for the card deck
  //you will need to complete the function.
  cout<<"-"<<endl;
  buildAndDeal();
  cout<<"-"<<endl;
  // Now the string checks with deques
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

void buildAndDeal()
{
  vector<card*> myDeck;
  int position = 0;
  for(int i = 0; i < 4; i++)
  {
    string newSuit;
    if(i == 0){newSuit = "hearts";}
    if(i == 1){newSuit = "spades";}
    if(i == 2){newSuit = "diamonds";}
    if(i == 3){newSuit = "clubs";}
    for(int j = 0; j <13; j++)
    {
      myDeck.push_back(new card);
      string newFace;
      if(j < 10){newFace = to_string(j+1);};
      if(j == 0){newFace = "ace";};
      if(j == 10){newFace = "jack";}
      if(j == 11){newFace = "queen";}
      if(j == 12){newFace = "king";}
      myDeck[position]->setFace(newFace);
      myDeck[position]->setSuit(newSuit);
      position++;
    }
  }
  //print deck, make sure you have it all!

  // DO NOT CHANGE THESE FOLLOWING TWO LINES OF CODE
  // OR THE FUNCTION UP TOP
  // it will break and you will be sad
  srand(unsigned(time(NULL)));
  random_shuffle(myDeck.begin(), myDeck.end(),myRand);

  cout<<"here is your hand"<<endl;
  for(int i =0; i<5 && i<myDeck.size(); i++)
  {
    cout<<myDeck.at(i)->getSuit()<<" "<<myDeck.at(i)->getFace()<<endl;
  }
}

bool parenCheck(string toCheck)
{
  deque<char> checker; //declare my queue
  for (int i = 0; i < toCheck.length(); i++){
    if (toCheck[i] == '('){ // else push (
      checker.push_front(toCheck[i]);
    }
    else if (toCheck[i] == ')' && checker.front() == '('){ // if given ), and front = (, pop the (
      checker.pop_front();
    }
    else {
      return false;
    };
  };

  if (checker.size() == 0){
    return true;
  };
  return false; //need a return statement to compile
}
string stringReverse(string toReverse)
{
  deque<char> reverse;
  string newString = "";
  for (int i = 0; i < toReverse.length(); i++){
    reverse.push_front(toReverse.at(i));
  }
  while (!reverse.empty()){
    newString += reverse.front();
    reverse.pop_front();
  }
  return newString;
}
