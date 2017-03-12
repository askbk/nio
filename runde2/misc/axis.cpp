#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  int X[N+1];
  int Y[N+1];
  for (size_t i = 1; i < N+1; i++) {
    scanf("%s", &X[i]);
    scanf("%s", &Y[i]);
  }
  
  return 0;
}
