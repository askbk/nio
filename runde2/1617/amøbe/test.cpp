#include <iostream>
#include <cmath>

bool nokSukker(long long sukker, long long timer, long long amober) {
  if (amober>1) { //mer en én amøbe
    if (timer>=1) { //minst én time igjen
      long long sukkerTrengt;
      if (amober%2==0) {
        sukkerTrengt = 2 * amober;
      } else {
        sukkerTrengt = 2 * (amober-1) + 1;
      }
      if (sukkerTrengt>sukker) {
        return false;
      }
      return nokSukker(sukkerTrengt, timer-1, ceil(amober/2));
    } else {
      std::cout << sukker << " er ikke nok sukker på " << timer << " for " << amober << std::endl;
      return false; //ikke nok timer dersom det er 0 timer og mer enn 1 amøbe
    }
  } else {
    if (amober<timer) {
      return false;
    }
    if (timer>=1) {
      if (sukker>=timer ) {
        std::cout << sukker << " er nok sukker på " << timer << " for " << amober << std::endl;
        return true;
      } else {
        std::cout << sukker << " er ikke nok sukker på " << timer << " for " << amober << std::endl;
        return false;
      }
    } else {
      std::cout << sukker << " er nok sukker på " << timer << " for " << amober << std::endl;
      return true;
    }
  }
}

long long number(long long k, long long T, long long n){  //sukker, timer, antall

  int logT = ceil(log2(T)); //logaritmen av maksimalt antall amøber ved ubegrenset sukker
  int t = 1; //
  long long count = 0;

  while (t<=logT) {
    if (nokSukker(k, T, n)) {
      count = n;
      n += exp2(T-t);
      std::cout << T << "-" << t << std::endl;
    } else {
      n -= exp2(T-t);
      std::cout << T << "-" << t << std::endl;
    }
    t++;
  }
  return count;
}

int main() {
  long long K, T, N;  //sukker, timer, antall amøber
  std::cin >> K >> T;

  if (exp2(T+2)-2>K) {
    N = ceil(K/2);
  }

  std::cout << number(K, T, N) << std::endl;

  return 0;
}
