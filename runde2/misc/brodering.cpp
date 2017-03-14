#include <iostream>

using namespace std;

int main(){
  int K, R, N, A, length = 0;
  char F;
  cin >> K >> R >> N;
  char brodering[K*R];
  for (size_t i = 1; i < N+1; i++) {
    cin >> A >> F;
    for (size_t j = 1; j < A+1; j++) {
      brodering[length+j] = F;
    }
    length += A;
  }

  for (size_t i = 0; i < R; i++) {
    if (i%2==0) {
      for (size_t j = 1; j < K+1; j++) {
        cout << brodering[i*K+j];
      }
      cout << "\n";
    } else {
      for (size_t j = K; j > 0; j--) {
        cout << brodering[i*K+j];
      }
      cout << "\n";
    }
  }

  return 0;
}
