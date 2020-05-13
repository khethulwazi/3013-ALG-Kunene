///////////////////////////////////////////////////////////////////////////////
//
// Author:           Khethulwazi Kunene
// Email:            khethokunene@gmail.com
// Label:            P05
// Title:            Program 05 - uVa problem 484
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       This program will map the number of occurences of a 
//       specified integer and dispay a reference table as an
//       output with the integer on the left and appearances on the right
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
  
  map<int, int> input;
  vector<int> appearances;
  int number;


  while( cin >> number){

    //looks for number in map
    if(input.find(number) == input.end()){
      appearances.push_back(number);
      input[number] = 1;
    } else {
          input[number] ++;
        
    }
  }
  for(int i =0; i < appearances.size(); i++){
    cout << appearances[i] << " " << input[appearances[i]] <<endl;
  }
  return 0;
}
