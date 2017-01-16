#include <iostream>
#include <cmath>

int main() {
  long long K, T;
  std::cin >> K >> T;

  long long* tree = new long long[T];
  long long sukkerTrengt = 0;
  long long antall = 0;
  bool solved = false;

  for (size_t i = 0; i < T; ++i) {
    tree[i] = 1;
  }

  while (sukkerTrengt<K && !solved) {
    sukkerTrengt = 0;
    for (size_t i = 0; i < T; ++i) {
      if (tree[i]>1) {
        sukkerTrengt += 4 * floor(tree[i] / 2) + (tree[i] % 2);
      } else {
        ++sukkerTrengt;
      }
    }
    if (sukkerTrengt<K) {
      if (T == floor(log2(tree[T-1]))) { //antall amøber kan aldri være høyere enn 2^T
        solved = true;
        antall += 1;
        break;
      }
      antall = tree[T-1];
      for (size_t i = T; i > 0; --i) {
        tree[i] += 1;
        if (tree[i]%2==0) { //dersom man la til en node på et nivå som ikke hadde et partall, trenger man ikke legge til foreldrenoder.
          break;
        }
      }
    } else {
      break;
    }
  }
  std::cout << antall << std::endl;
  return 0;
}
