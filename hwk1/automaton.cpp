/*
Alejandro Aquino
Theory of Computing - CS421

Description: This program will identify email messages that are 
spam email given a collection of emails.
 */

//preprocessors
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
 
  const int strMax = 100; // max size for the array
  ifstream fin; //input for the file
  char phrase; //each letter
  int num = 0;  
  char temp[20];
  int arr = 0;
  int count=0; // keeps track of count
  int accept[16];
  vector <char> symbol; //used for each vector stored
  string state[strMax] = {"q0", "q1", "q2", "q3", "q4", "q5", "q6", "q7", "q8", "q9", "q10",
			  "q11", "q12", "q13", "q14", "q15", "q16", "q17","q18", "q19","q20",
			  "q21", "q22", "q23", "q24", "q25", "q26", "q27", "q28", "q29","q30",
			  "q31", "q32", "q33", "q34", "q35", "q36", "q37", "q38", "q39", "q40",
			  "q41", "q42", "q43", "q44", "q45", "q46", "q47", "q48", "q49", "q50",
			  "q51", "q52", "q53", "q54", "q55", "q56", "q57", "q58", "q59", "q60",
			  "q61", "q62", "q63", "q64", "q65", "q66", "q67", "q68", "q69", "q70", 
			  "q71", "q72", "q73", "q74", "q75", "q76", "q77" ,"q78", "q79"};
  
  fin.open("messagefile.txt");//opening file 

  //if file does not exist then displays error
  if(!fin)
    {
      cout << "File does not exist" << endl;
      exit(1);
    }
  //if it does exist goes into the else
  else
    {      
      while(fin)
	{
	  fin >> noskipws >> phrase;
	  symbol.push_back(phrase);
	}

      for(int i=0; i< symbol.size();i++)
	{
	  switch(symbol[i])
	    {
	    case '<': if(state[num] == "q0") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      if(state[num] == "q6") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      if(state[num] == "q19") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      if(state[num] == "q74") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      break;
	    case 'D': if(state[num] == "q1") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      if(state[num] == "q7") {cout << state[num] << " -> " << symbol[num] << endl; num++;}
	      if(state[num] == "q11") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      if(state[num] == "q21") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      if(state[num] == "q25") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      if(state[num] == "q76") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      break;
	    case 'O': if(state[num] == "q2") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      if(state[num] == "q8") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      if(state[num] == "q22") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      if(state[num] == "q77") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      break;
	    case 'C': if(state[num] == "q3") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      if(state[num] == "q9") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      if(state[num] == "q23") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      if(state[num] == "q78") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      break;
	    case '>': if(state[num] == "q4") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
              if(state[num] == "q12") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      if(state[num] == "q26") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      if(state[num] == "q79") {cout << state[num] << " -> " << symbol[i] << endl; num=0;}
	      break;
	    case '\n': if(state[num] == "q5") {cout << state[num] << " -> 'Empty Space'" << symbol[i] << endl; num++;}
	      if(state[num] == "q27") {cout << state[num] << " -> 'Empty Space'" << symbol[i] << endl; num++;}
	      if(state[num] == "q39") {cout << state[num] << " -> 'Empty Space'" << symbol[i] << endl; num++;accept[count] = arr; count++;}
	      break;
	    case ' ': if(state[num] == "q13") {cout << state[num] << " -> 'Empty Space'" << symbol[i] << endl; num++;}
	      if(state[num] == "q18") {cout << state[num] << " -> 'Empty Space'" << symbol[i] << endl; num++;}
	      if(state[num] == "q32") {if(symbol[i-1] == 'e'){cout << state[num] << " -> 'Empty Space'" << symbol[i] << endl; num++;}}
	      if(state[num] == "q47") {if(symbol[i-1] == 'e'){cout << state[num] << " -> 'Empty Space'" << symbol[i] << endl; num++;}}
	      if(state[num] == "q73") {if(symbol[i-1] == ' ')cout << state[num] << " -> 'Empty Space'" << symbol[i] << endl; num++;}//continue here
	      break;
	    case 'I': if(state[num] == "q10") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      if(state[num] == "q24") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      break;	      
	    case 'm': if(state[num] == "q14") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
              break;
	    case 's': if(state[num] == "q15") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      if(state[num] == "q33") {if(symbol[i-1] == ' '){cout << state[num] << " -> " << symbol[i] << endl; num = 40;}}
	      if(state[num] == "q37") {if(symbol[i-1] == 'e'){cout << state[num] << " -> " << symbol[i] << endl; num++;}}
              if(state[num] == "q38") {if(symbol[i-1] == 's'){cout << state[num] << " -> " << symbol[i] << endl; num++;}}	      
	      break;
	    case 'g': if(state[num] == "q16") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
              break;
	    case '1': if(state[num] == "q17") {cout << state[num] << " -> " << symbol[i] << endl; num++;arr=1;}
	      break;
	    case '2': if(state[num] == "q17") {cout << state[num] << " -> " << symbol[i] << endl; num++;arr=2;}
              break;
	    case '3': if(state[num] == "q17") {cout << state[num] << " -> " << symbol[i] << endl; num++;arr=3;}
              break;
	    case '4': if(state[num] == "q17") {cout << state[num] << " -> " << symbol[i] << endl; num++;arr=4;}
              break;
	    case '5': if(state[num] == "q17") {cout << state[num] << " -> " << symbol[i] << endl; num++;arr=5;}
              break;
	    case '6': if(state[num] == "q17") {cout << state[num] << " -> " << symbol[i] << endl; num++;arr=6;}
              break;
	    case '7': if(state[num] == "q17") {cout << state[num] << " -> " << symbol[i] << endl; num++;arr=7;}
              break;
	    case '8': if(state[num] == "q17") {cout << state[num] << " -> " << symbol[i] << endl; num++;arr=8;}
              break;
	    case '9': if(state[num] == "q17") {cout << state[num] << " -> " << symbol[i] << endl; num++;arr=9;}
              break;
	    case 'f': if(state[num] == "q28") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      if(state[num] == "q41") {if(symbol[i-1] == 'o'){cout << state[num] << " -> " << symbol[i] << endl; num++;}}
	      break;
	    case 'r': if(state[num] == "q29") {if(symbol[i-1] == 'f'){cout << state[num] << " -> " << symbol[i] << endl; num++;}}
	      if(state[num] == "q45") {if(symbol[i-1] == 'a'){cout << state[num] << " -> " << symbol[i] << endl; num++;}}
	      break;
	    case 'e': if(state[num] == "q30") {if(symbol[i-1] == 'r'){cout << state[num] << " -> " << symbol[i] << endl; num++;}}
	      if(state[num] == "q31") {if(symbol[i-1] == 'e'){cout << state[num] << " -> " << symbol[i] << endl; num++;}}
	      if(state[num] == "q36") {if(symbol[i-1] == 'c'){cout << state[num] << " -> " << symbol[i] << endl; num++;}}
	      if(state[num] == "q46") {if(symbol[i-1] == 'r'){cout << state[num] << " -> " << symbol[i] << endl; num = 73;}} //u stoped here
	      break;
	    case 'a': if(state[num] == "q33") {if(symbol[i-1] == ' '){cout << state[num] << " -> " << symbol[i] << endl; num++;}}
              if(state[num] == "q44") {if(symbol[i-1] == 'w'){cout << state[num] << " -> " << symbol[i] << endl; num++;}}
	      break;
	    case 'c': if(state[num] == "q34") {if(symbol[i-1] == 'a'){cout << state[num] << " -> " << symbol[i] << endl; num++;}}
	      if(state[num] == "q35") {if(symbol[i-1] == 'c'){cout << state[num] << " -> " << symbol[i] << endl; num++;}}
	      break;
	    case '/': if(state[num] == "q20") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      if(state[num] == "q75") {cout << state[num] << " -> " << symbol[i] << endl; num++;}
	      break;
	    case 'o': if(state[num] == "q40") {if(symbol[i-1] == 's'){cout << state[num] << " -> " << symbol[i] << endl; num++;}}
            case 't': if(state[num] == "q42") {if(symbol[i-1] == 'f'){cout << state[num] << " -> " << symbol[i] << endl; num++;}}
	    case 'w': if(state[num] == "q43") {if(symbol[i-1] == 't'){cout << state[num] << " -> " << symbol[i] << endl; num++;}}
	    }//end of switch
	}//end of for loop
    }//end of else

  cout << "the message email that are spams are: " << endl;
  for(int i=0;i<count;i++)
    {
      cout << "msg #" << accept[i] << endl;
    } // end of for loop
  fin.close(); //this closes the file
  return 0;
}
