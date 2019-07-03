/*
Alejandro Aquino
Programming Assignment #2
CS421 - Theory of Computing
Programming Language: C++

Description: This program will implement a parser that processes sequences
of correctly paired ifs and else. This stimulates a PDA.
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <stack>
using namespace std;

void displayAll(vector<char> &stack);

//declaring the max size for the array
int MAX_SIZE = 50;

int main()
{
  //input declarations
  char symbol[MAX_SIZE];
  ifstream fin;
  char cRead;
  vector <char> letter;
  stack <char> mystack;
  vector <char> stack;
  int lSize;

  //opening file
  fin.open("sequence.txt");

  //if files does not exist
  if(!fin)
    {
      cout << "File does not exist or did not match." << endl;
      exit(1);
    }
  //otherwise the file exist
  else
    {
      while(fin)//while a character still exist
	{
	  fin >> cRead;
	  letter.push_back(cRead);
	}
      //to get the size of the letter vector
      lSize = letter.size();
      
      cout << "**********************************************" << endl;
      cout << "*****         PDA Simulator              *****" << endl;
      cout << "**********************************************" << endl;
      displayAll(stack);
      cout << "***************************************************" << endl;
      
      //parsing the sequence 
      for(int i=0; i<lSize;i++)
	{
	  
	  switch(letter[i])
	    {
	      //check case i for if
	    case 'i':
		  cout << "pushing to the stack...:" << letter[i] << endl;
		  mystack.push(letter[i]);
		  stack.push_back(letter[i]);
		  displayAll(stack);
		  i++;// to skip f on the word 'if'
		  cout << "************************************************" << endl;
		  break; 
	    case 'e':
	      cout << "Popping the stack..." << endl; 
	      mystack.pop();
	      stack.pop_back();
	      displayAll(stack);
	      i = i + 3;// to skip else on the word 'else'
	      cout << "************************************************" << endl;
	      break;
	      
	    case '{':
	      cout << "Popping the stack..." << endl;
	      mystack.pop();
              stack.pop_back();
	      displayAll(stack);
	      cout << "************************************************" << endl;
	      break;
	    
	    case '}':
	      cout << "Popping the stack..." << endl;
	      mystack.pop();
              stack.pop_back();
	      displayAll(stack);
	      cout << "************************************************" << endl;
	      break;
	    }
	  
	}// end of for loop
      
      //to check to see if the stack is empty and accepted
      if(stack.empty())
	{
	  cout << "Correct Sequence" << endl;
	}
      else
	{
	  cout << "The sequence is syntactically incorrect" << endl;
	  exit(1);
	}
    }
  
  fin.close();//this closes the file 
  return 0;//return with no errors
}

//this function will display the vector stack
void displayAll(vector<char> &stack)
{
  //if the stack is empty then it will displays 
  if(!stack.empty())
    {
      cout << "---[Displaying Stack: ";
      for(int i=0;i<stack.size();i++)
	{
	  cout << stack[i] << " ";
	} 
      cout << "]---\n" << endl;
   }

  //if not then it will display a message
  //saying that the stack is empty
  else
    {
      cout << "---[The Stack is empty]---" << endl;
    }
}
