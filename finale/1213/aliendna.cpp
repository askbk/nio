#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  char DNA[N];
  for (size_t i = 0; i < N; i++) {
    cin >> DNA[i];
  }

  int max = 0;
  char first = DNA[0], second = DNA[1];
  int secondLength = 1;
  int length = 2;

  for (size_t i = 2; i < N; i++) { //itererer gjennom DNAet
    if (DNA[i] == first) {
      char temp = second;
      second = first;
      first = temp;
      length++;
      secondLength = 1;
    } else if(DNA[i] == second){
      secondLength++;
      length++;
    } else {
      if (length>max) {
        max = length;
      }
      first = second;
      second = DNA[i];
      length = secondLength + 1;
      secondLength = 1;
    }
  }
  cout << max;
}
