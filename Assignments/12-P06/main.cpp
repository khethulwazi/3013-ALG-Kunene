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
