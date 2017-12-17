/**
 * File: main.cpp
 * Developer: Anthony Serrano
 * Email: serranoa137164@student.vvc.edu
 * Description: A concordance generator program that will list of all the words found in a text file with a count of the number of times the word occurred and a comma delimited list of the line numbers of where  the word occurred.All letters in the string will be forced to lowercase. A track of the current line number and if the word has been found beforewill be kept.  If the word has been found before,the line number of where the word occurred will be stored. 
**/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctype.h>
#include <sstream>

int main()
{
  char file[20];
  
  double line=0;

  std:: string lines[1000];
  std:: string word;
  std:: string concord[1000];

  int count[1000]={0};
  int index=0;

  std::ifstream in_f;

  in_f.open("alice.txt");
  std::string temp;

  while(in_f.good())
  {
    std:: getline(in_f,word);//read in line by line

    //removing punctations and converting upper case letters to lower case
    for(int i=0;i<word.length();i++)
    {
      if(!isalpha(word.at(i)))
      {
        if(word.at(i)!=' ')

        for(int j=i;j<word.length()-1;j++)
        {
          word.at(j)=word.at(j+1);
        }
        if(i==word.length()-1)
          word.at(i)=' ';
      }
      if(!islower(word.at(i)))
      {
        word.at(i)=tolower(word.at(i));
      }
    }
    
    std::istringstream iss(word);
    while(iss>>temp) //read each word in each line
    {
      bool flag = false;
      int matchedAt = -1;

      for(int k=0; k<index; k++)
      {
        if(concord[k]==temp)
        {
          flag=true;
          matchedAt=k;
        }
      }
      if(flag!=true)
      {
        concord[index]=temp;
        count[index]=1;
        std::stringstream num;
        num<<line+1;
        lines[index]=num.str();
        index++;
      }
      else
      {
        count[matchedAt]++;
        std::stringstream numb;
        numb<<line+1;
        lines[matchedAt]=lines[matchedAt]+","+numb.str();
      }
    }
    line=line+1;
  }

  //print concord
  std::cout << std::left<< std::setw(15) << "Word"<< std::setw(3)<<" : " << "count" << std::setw(3) << " : "
       <<"Occurences"<< std::endl;

  std::cout << "----------------------------------------------------------------------------" << std::endl;

  for(int l=0;l<index;l++)

  std::cout << std::left << std::setw(15) << concord[l]<< std::setw(5) << " : " << count[l] << std::setw(3) << " : "
       << lines[l] << std::endl;
  return 0;
}
