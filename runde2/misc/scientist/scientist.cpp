#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[]) {
  priority_queue<long long> ressurser;
  long long inp;
  long long ress[3];
  long long hus = 0;
  int N;

  cin >> N;
  for (size_t i = 0; i < N; i++) {
    cin >> inp;
    ressurser.push(inp);
  }

  while (ressurser.size() > 2) {
    for (size_t i = 0; i < 3; i++) {
      ress[i] = ressurser.top();
      ressurser.pop();
    }
    hus += ress[2];
    for (size_t i = 0; i < 2; i++) {
      ress[i] -= ress[2];
      if (ress[i]!=0) {
        ressurser.push(ress[i]);
      }
    }
  }

  cout << hus;
  return 0;
}
