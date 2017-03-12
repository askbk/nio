#include <iostream>
#include <cstring>
#include <bitset>

using namespace std;

# define MAX 1000000

int main() {
  long long N;
  cin >> N;
  bitset<MAX> lights;
  lights.set();
  //long long DP[N+1];
  //long long lights;
  //memset(lights, 1, sizeof lights);

  for (size_t i = N; i > 0; i--) {  // K dager
    for (size_t j = 1; j < N+1; j++) {  // N hus
      if (j%i == 0) {
        lights.flip(j);
      }
    }
  }

  std::cout << (lights.count()-1-(MAX - N)) << "\n";
  return 0;
}
