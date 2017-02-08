#include <iostream>
#include <string>
#include <cmath>

int main() {
  std::string passord;
  std::string alfabet = "abcdefghijklmnopqrstuvwxyz";
  std::string alfaNum = "0123456789abcdefghijklmnopqrstuvwxyz";
  int N;
  std::cin >> passord;
  int passLength = passord.size();

  if (passLength == 1) {
    N = alfabet.find_first_of(passord);
  } else if (passLength == 2) {
    N = 26 + alfabet.find_first_of(passord.front())*36 + alfaNum.find_first_of(passord.at(1));
  } else {

    for (size_t i = 0; i < passLength; i++) {
      if (i=0) {
        N += alfabet.find_first_of(passord.at(i)) * pow(36, passLength - i - 1);
      } else {
        N += alfaNum.find_first_of(passord.at(i)) * pow(36, passLength - i - 1);
      }
    }

    if (passLength > 1) {
      for (size_t i = 0; i < passLength - 2; i++) {
        N += 26*pow(36, i);
      }
    }
  }
  std::cout << N << std::endl;
  return 0;
}
