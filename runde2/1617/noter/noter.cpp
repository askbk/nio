#include <iostream>
#include <cmath>

int main() {
  double A, B;
  std::cin >> A >> B;
  double ratio = B/A;
  int X = 1;
  int Y = 1;
  double frac = Y/(double)X;

  while (fabs(ratio - frac) >= 0.003) {
    if (frac > ratio) {
      X++;
    } else if (frac < ratio){
      Y++;
    }
    frac = Y/(double)X;
  }
  std::cout << X << " " << Y << std::endl;

  return 0;
}
