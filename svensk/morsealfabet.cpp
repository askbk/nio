#include <iostream>
#include <map>
#include <array>
#include <string>

int main(int argc, char const *argv[]) {
  std::map<std::string, std::string> alf;
  std::string S1;
  std::string S2;
  int S;
  int P;
  int T;
  int B;
  int M;
  int N;
  int morse;

  for (size_t i = 0; i < 26; i++) {
    std::cin >> S1 >> S2;
    alf[S1]=S2;
  }

  std::cin >> S >> P >> T >> B >> M >> N >> morse;
  return 0;
}
