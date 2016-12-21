#include <iostream>

int main() {
  int N;
  long long A;
  long long B;
  char op;
  std::cin >> N;
  for (size_t i = 0; i < N; ++i) {
    long long result;
    std::cin >> A >> op >> B;
    switch (op) {
      case '*':
        result = A * B;
        std::cout << result << std::endl;
        break;
      case '+':
        result = A + B;
        std::cout << result << std::endl;
        break;
      case '-':
        result = A - B;
        std::cout << result << std::endl;
        break;
    }
  }
  return 0;
}
