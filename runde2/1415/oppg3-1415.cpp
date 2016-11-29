#include <iostream>
#include <array>

int main() {
  int n;  //count
  int m;  //count
  int h;  //temporary variable
  int N;  //temporary variable
  int M;
  int alt[N][M];  //array for altitude
  int att[N][M];  //array for attractions

  std::cin >> n >> m;

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      std::cin >> N;
      alt[i][j] = N;
    }
  }

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      std::cin >> N;
      att[i][j] = N;
    }
  }

  return 0;
}
