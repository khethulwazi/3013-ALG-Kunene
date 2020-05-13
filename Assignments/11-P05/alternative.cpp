#include <iostream>
#include <vector>
using namespace std;
//Function decleration
bool findNum(vector<int> v, int num);
int main(int argc, char **argv)
{
  int size = 15;
  vector<int> input(size);
  vector<int> appearances(size);
  int number;
  int position = 0;

  while( cin >> number){

    //This will add an integer and set the count
    //if the number has been found it will not be added
    if(findNum(input, number) != true || position == 0){
      input[position] = number;
      appearances[position++] = 1;
    } else {
      //Ths will increment the appropriate index
      //for the appearances vector for the given integer
        for(int i = 0; i < size-1; i++){
          if (number == input[i]){
          appearances[i] ++;
          }
        }
    }
  }
  for(int i =0; i < position; i++){
    cout << input[i] << " " << appearances[i] <<endl;
  }
  return 0;
}
//Function fuindNum is a linear search for given integer
//returns true if the number is found
//receives vector to be searched and integer to be found
bool findNum(vector<int> v, int num){
  bool found = false;
  if (v.empty() == true){
    found = false;
    return found;
  }
  for (int i = 0; i < v.size(); i++){
    if (num == v[i]){
    found = true;
    }
  }
  return found;
}
