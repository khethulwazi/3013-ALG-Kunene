///////////////////////////////////////////////////////////////////////////////
//
// Author:           Khethulwazi Kunene
// Email:            khethokunene@gmail.com
// Label:            P06
// Title:            Program 06 - Spanning subtrees uVa problem 11597
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//    This program will find the maximum number of spanning trees of 
//    a complete undirected graph that can be formed in such a way that 
//    no two of these spanning trees have a common edge.
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  int number;
  int caseNum = 0;

  while (cin >> number && number != 0){
    caseNum++;
    cout << "Case " << caseNum << ": " << number/2 << endl;   
  }

  return 0;
}
