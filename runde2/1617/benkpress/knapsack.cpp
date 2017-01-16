#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
  int W, N, curW, T1, T2;

  std::cin >> W >> N;

  int volum[N], weight[N], m[N][W];

  for (size_t i = 0; i < N; i++) {
    std::cin >> T1 >> T2;
    volum[i] = T1;
    weight[i] = T2;
  }

  for (size_t j = 0; j < W; j++) {
    m[0][j] = 0;
  }

  for (size_t i = 1; i < N; i++) {
    for (size_t j = 0; j < W; j++) {
      if (weight[i] > j) {
          m[i][j] = m[i-1][j];
      } else {
        m[i][j] = std::max(m[i-1][j], m[i-1][j-weight[i]] + volum[i]);
      }
    }
  }
  for (size_t i = 0; i < count; i++) {
    std::cout << m[0][W] << std::endl;
  }
  std::cout << m[N][W] << std::endl;
  return 0;
}
