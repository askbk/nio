#include <iostream>
#include <algorithm>
#include <vector>

bool wayToSort(int i, int j) { return i > j; }

int main() {
  int N;
  int hus = 0;
  long long tem;
  std::cin >> N;
  std::vector<long long> ressurser;

  for (size_t i = 0; i < N; ++i) {
      std::cin >> tem;
      ressurser.push_back(tem);
  }

  std::sort(ressurser.begin(), ressurser.end(), wayToSort);

  while (ressurser.size() > 2) {
    if (ressurser.size() > 3) {
      if (ressurser[2]<ressurser[3]) {
        std::sort(ressurser.begin(), ressurser.end(), wayToSort);
      }
      for (size_t i = 0; i < 3; i++) {
        ressurser[i] = ressurser[i] - ressurser[3];
      }
      hus += ressurser[3];
      /*if (ressurser[2]>ressurser[3]) {
        int diff = ressurser[2]-ressurser[3]+1;
        for (size_t i = 0; i < 3; ++i) {
          ressurser[i] = ressurser[i] - diff;
        }
        hus += diff;
      } else {
        hus++;
        for (size_t i = 0; i < 3; ++i) {
          ressurser[i] = ressurser[i] - 1;
        }
      }*/
    } else {
      hus++;
      for (size_t i = 0; i < 3; ++i) {
        ressurser[i] = ressurser[i] - 1;
      }
    }

    if (ressurser[0]==0) {
      ressurser.erase(ressurser.begin());
      if (ressurser[0]==0) {
        ressurser.erase(ressurser.begin());
        if (ressurser[0]==0) {
          ressurser.erase(ressurser.begin());
        }
      }
    } else if (ressurser[1]==0) {
      ressurser.erase(ressurser.begin() + 1);
      if (ressurser[1]==0) {
        ressurser.erase(ressurser.begin() + 1);
      }
    } else if (ressurser[2]==0) {
      ressurser.erase(ressurser.begin() + 2);
    }
  }
  std::cout << hus << std::endl;
  return 0;
}
