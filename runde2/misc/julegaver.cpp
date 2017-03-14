#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;



int main(){
  int N, K, a;
  cin >> N;
  vector< vector <int> > edge;
  int color[N]; // verdi 0 eller 1, den det er flest av er bok
  vector<bool> visited;
  queue<int> que;
  edge.resize(N);
  visited.resize(N);

  memset(color, -1, sizeof color);

  for (size_t i = 0; i < N; i++) {
    cin >> K;
    for (size_t j = 0; j < K; j++) {
      cin >> a;
      edge[i].push_back(a);
      edge[a].push_back(i);
    }
  }

  color[0] = 0;
  que.push(0);

  while(!que.empty()){
    int current = que.front();
    que.pop();
    visited[current] = true;
    for (size_t i = 0; i < edge[current].size(); i++) {
      int temp = edge[current][i];
      if (!visited[i]) {
        que.push(temp);
        if (color[current]==1) {
          color[temp] = 0;
        } else {
          color[temp] = 1;
        }
      }
    }
  }

  for (size_t i = 0; i < N; i++) {
    if (color[i]==-1) {
      cout << 0;
      return 0;
    }
  }
  int count0 = count(color, color+N, 0);
  int count1 = count(color, color+N, 1);
  if (count1 == count0) {
    cout << 0;
    return 0;
  }

  cout << max(count0, count1);

  return 0;
}
