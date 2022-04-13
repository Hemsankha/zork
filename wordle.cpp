#include "wordle.h"
#include <iostream>
#include <fstream>
#include <string>

#define numWords 5
using namespace x;

string wordList[numWords];
string input;
string txtFile;
vector<string> singleWord;
vector<string> singleWordInput;

wordle::wordle()
{
string txtFile = "wordle.txt.txt";
input = " ";
}

void wordle::reader()
{

fstream newfile;

newfile.open(txtFile,ios::in); //open a file to perform read operation using file object
if (newfile.is_open()){ //checking whether the file is open
   string tp;
   while(getline(newfile, tp)){ //read data from file object and put it into string.
      for(int i= 0;i<numWords;i++)
      {
           wordList[i]=tp;
      }
      tp =" ";
   }
   newfile.close();
   txtFile =" ";//close the file object.
 }
}

int wordle::game(Command command){

    int success = 0;
    if (!command.hasSecondWord()) {
        cout << "Enter only one word"<< endl;
        success = 0;
    }
    else
     input = command.getCommandWord();

    const string word = "start";
          cout << "Welcome to Wordle" << endl;

          wordArray(input, singleWordInput);


          int j = 0, successCount=0;
          while(j<3){
          for (int i = 0; i < 5; i++)
          {

          wordArray(wordList[i],singleWord);

          for(int k=0;k < singleWord.size();k++)
          {

          if(singleWord[k].compare(singleWordInput[k])!=0){
              j++;
            cout << "the letter doesn't match." << endl;

          }
          else{
            cout << "You guessed the letter!";
            if(successCount<singleWord.size())
             successCount++;
            else{
                success = 1;
                break;
          }
          }
          singleWord.clear();

       }

   }
          singleWordInput.clear();
 }
          return success;

}

void wordle::wordArray(string i, vector<string> v)
{

    string copy =i;
    int len = i.length();
    int pos, prevPos;
    for(int i =1; i<=len-1;i++)
    {
        pos = i;
        prevPos = 0;


        v.push_back(copy.substr(prevPos,pos));
        prevPos = i;
    }
}

