#include <iostream>

using namespace std;

int main(){
  long long m, n;
  int count = 0;
  cin >> m >> n;

  for (long long i = m; i <= n; ++i) {
    if ((i%10)==0) {
      continue;
    }
    long long temp = i, tempAdd = 0, tempMulti = 1;
    while (temp > 0) {
      int siffer = temp % 10;
      temp /= 10;
      tempAdd += siffer;
      tempMulti *= siffer;
    }

    if (tempAdd==tempMulti) {
      ++count;
    }
  }
  cout << count;
  return 0;
}
