#include <iostream>
#include <map>
#include <algorithm>
#include <functional>

struct vektplate{
  int volum;
  int vekt;
} ;

bool wayToSort (int i,int j) { return (i<j); }

int main() {
  int W, N; //maxvekt, antall par
  int volum;
  int curW;
  int T1, T2;
  double ratio;
  std::map<double, vektplate> wPair;
  std::cin >> W >> N;

  for (size_t i = 0; i < N; ++i) {
    std::cin >> T1 >> T2; //input for vekt, volum
    ratio = T2/T1;  //forhold
    wPair[ratio].vekt = T1;
    wPair[ratio].volum = T2;
  }

  for (auto& x: wPair) {
    if (curW == W) {
      std::cout << volum << std::endl;
      return 0;
    }
    if ((curW + x.second.vekt) <= W) {
      curW += x.second.vekt;
      volum += x.second.volum;
    }
  }
  std::cout << volum << std::endl;

  return 0;
}
