#include <iostream>
#include <map>

int main(int argc, char const *argv[]) {
  int N;
  int A;
  int B;
  std::map<int, int> gate;

  for (size_t i = 1; i < N; i++) {
    std::cin >> A >> B;
    gate[A] = B;
  }

  return 0;
}
