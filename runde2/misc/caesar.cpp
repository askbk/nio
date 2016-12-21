#include <iostream>
#include <functional>

int main() {
  int N;
  const std::string alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const int modN = alfabet.size();
  std::string inp;
  std::string out;
  std::cin >> N >> inp;
  const int msgSize = inp.length();

  for (int i = 0; i < msgSize; ++i) {
    char A; //midlertidig variabel for input-bokstaven
    A = inp.at(i);
    int index = (A + N - 65) % modN; //bokstavens posisjon i alfabetet
    out.push_back(alfabet.at(index));
  }
  std::cout << out << std::endl;
  return 0;
}
