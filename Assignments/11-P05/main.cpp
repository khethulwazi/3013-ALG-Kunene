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
