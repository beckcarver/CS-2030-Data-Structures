//Danny Radosevich
//Lab 7
//Written for UWYO COSC 2030

#include<iostream>

using namespace std;

#define HASHSIZE 73
//whatever the size of your array woulld be

int example(string toHash);
int hasher(string toHash);
int main()
{
  string input = "";
  bool control = true;
  while(control)
  {
    cout<<"Enter somthing to hash, STOP to stop"<<endl;
    cin>>input;
    if(input=="STOP")
    {
      control =false;
    }
    else
    {
      cout<<"Ward's hash returned "<<to_string(example(input))<<endl;
      cout<<"Your hash returned "<<to_string(hasher(input))<<endl;

    }
  }
  return 0;
}
int example(string toHash)
{
  int i; long int val=0;
  for (i=0; i<=toHash.size(); i++)
  {
    val+= (int)toHash[i] * (i*i);
  }
  //divide by the size of the array to make sure you always get something within bounds
  return val%HASHSIZE;
}
int hasher(string toHash)
{
    long long int val = 0;
    srand(1);                           // ensures rand() starts with the same seed
    for(int i = 0; i < toHash.length(); i++){
        srand (toHash[i]+rand());       // sets seed to hash value plus a random number from old seed
        val += rand();                  // adds to value with the newly seeded random number
    }
    return val % HASHSIZE;              // I changed hashsize to 100 for fun 
}  
