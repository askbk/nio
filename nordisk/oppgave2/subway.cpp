#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int N, a, b;  //stasjoner, stasjon a, stasjon b
  cin >> N;
  vector< vector<int> > currentTracks(N);  //naboliste
  vector< vector<int> > plannedTracks(N);  //naboliste
  //queue< vector < vector <int> > >

  for (size_t i = 0; i < N-1; i++) {
    cin >> a >> b;
    currentTracks[a].push_back(b);
    currentTracks[b].push_back(a);
  }

  for (size_t i = 0; i < N-1; i++) {
    cin >> a >> b;
    plannedTracks[a].push_back(b);
    plannedTracks[b].push_back(a);

  }



  return 0;
}
