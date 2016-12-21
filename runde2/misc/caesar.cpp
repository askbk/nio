#include <iostream>
#include <functional>

int main() {
  int N;
  const std::string alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const int modN = alfabet.size();
  std::string inp;
  std::string out;
  std::cin >> N >> inp;
  const int msgSize = inp.size() - 1;

  for (int i = 0; i <= msgSize; ++i) {
    char A; //midlertidig variabel for input-bokstaven
    A = inp.at(i);
    int index = A - 64; //bokstavens posisjon i alfabetet
    index += N; //forskyvning
    int indexX = index % modN; //
    out.push_back(alfabet.at(indexX - 1));
  }
  std::cout << out << std::endl;
  return 0;
}
