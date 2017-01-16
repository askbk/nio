#include <iostream>
#include <cmath>

bool nokSukker(int sukker, int timer, int amober) {
  if (amober>1) { //mer en én amøbe
    if (timer>=1) { //minst én time igjen
      nokSukker(floor(amober/2)+(amober%2), timer-1, ceil(amober/2)); //sjekker om det er nok for tidligere generasjoner
    } else {
      return false; //ikke nok timer dersom det er 0 timer og mer enn 1 amøbe
    }
  } else {
    if (timer>=1) {
      if (sukker-timer >=0 ) {
        return true;
      } else {
        return false;
      }
    } else {
      return true;
    }
  }
}

int number(int k, int T, long long n){

  int logT = ceil(log2(T));
  int t = logT - 1;

  while (t<=T) {
    if (nokSukker(k, logT - t, n)) {
      n += exp2(logT-t);
      std::cout << logT << "-" << n << std::endl;
    } else {
      n -= exp2(logT-t);
      std::cout << logT << "-" << n << std::endl;
    }
    t++;
  }
  return n;
}

int main() {
  long long K, T, N;
  bool solved = false;
  std::cin >> K >> T;

  N = exp2(ceil(log10(T) / log10(2)));

  std::cout << number(K, T, N) << std::endl;

  return 0;
}
