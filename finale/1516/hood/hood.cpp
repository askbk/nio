#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int P, N;
  cin >> P >> N;
  int F[N];
  int sum[N];

  for (size_t i = 0; i < N; i++) {
    cin >> F[i];
  }

  sort(F, F+N);

  sum[0] = F[0];

  for (size_t i = 1; i < N; i++) {
    sum[i] = sum[i-1] + F[i];
  }

  pair<int, int> match;
  match.first = 0;
  match.second = 2000000000;

  for (size_t i = 0; i < N; i++) {
    int *it = lower_bound(sum, sum+N, P+sum[i]);
    int index = it - sum;
    if (!(it == sum + N)) {
      if (F[index] - F[i+1] < match.second - match.first) {
        match.first = F[i+1];
        match.second = F[index];
      }
    }
  }

  cout << match.first << " " << match.second;
  
  return 0;
}
