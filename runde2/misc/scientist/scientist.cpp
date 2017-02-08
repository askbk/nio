#include <iostream>
#include <algorithm>
#include <vector>

bool wayToSort(int i, int j) { return i > j; }

int main() {
  int N;
  long long hus = 0;
  long long tem;
  long long arr[3];
  long long sum;
  std::cin >> N;
  std::vector<long long> ressurser;

  for (size_t i = 0; i < N; ++i) {
      std::cin >> tem;
      ressurser.push_back(tem);
  }

  std::sort(ressurser.begin(), ressurser.end(), wayToSort);

  while (ressurser.size() > 2) {


    for (size_t i = 0; i < 3; ++i) {
      arr[i]=ressurser[i];
    }

    std::sort(std::begin(arr), std::end(arr));


    for (size_t i = 0; i < 3; i++) {
      ressurser[i]=ressurser[i] - arr[0];
    }

    hus += arr[0];

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
