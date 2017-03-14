#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int N, T;
  cin >> N >> T;
  int posisjon[N];
  int aktuelt;

  for (size_t i = 0; i < N; i++) {
    cin >> posisjon[i];
  }

  sort(posisjon, posisjon + N);

  for (size_t i = 0; i < T; i++) {
    cin >> aktuelt;
    int *lower = lower_bound(posisjon, posisjon + N, aktuelt); // huset etter aktuelt hus
    int Idx = lower - posisjon;
    int avstand = 0;

    if (Idx == 0) {
      avstand = abs(posisjon[Idx]-aktuelt);
    } else if (Idx == N) {
      avstand = abs(posisjon[Idx - 1]-aktuelt);
    } else {
      avstand = min(abs(posisjon[Idx]-aktuelt), abs(posisjon[Idx - 1]-aktuelt));
    }
    cout << avstand << "\n";
  }
}
