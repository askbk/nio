#include <iostream>

int main() {
  long long N;
  int M;
  std::cin >> N >> M;

  for (size_t i = 0; i < M; i++) {
    long long G;
    std::cin >> G;
    if (G>N) {
      std::cout << "FOR MYE" << std::endl;
    } else if (G<N) {
      std::cout << "FOR LITE" << std::endl;
    } else {
      std::cout << "RIKTIG" << std::endl;
    }
  }
  return 0;
}
