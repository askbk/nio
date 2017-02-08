#include <iostream>

int main() {
  int N, T, t;
  int plassering = 1;
  std::cin >> T >> N;

  for (size_t i = 0; i < N; i++) {
    std::cin >> t;
    if (t<T) {
      ++plassering;
    }
    std::cout << plassering << std::endl;
  }
  return 0;
}
