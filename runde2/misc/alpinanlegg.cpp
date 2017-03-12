#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
  int N, u, M, a, b;
  cin >> N >> u >> M;
  vector< vector<int> > edge;
  vector<int> incoming;
  queue<int> que;

  edge.resize(N);
  incoming.resize(N);

  for (size_t i = 0; i < N; i++) {
    incoming[i] = 0;
  }

  for (size_t i = 0; i < M; i++) {
    cin >> a >> b;
    edge[b].push_back(a);
  }

  que.push(u);

  while(!que.empty()){
    int current = que.front();
    que.pop();
    for(int i = 0; i < edge[current].size(); ++i){
      int node = edge[current][i];
      incoming[node] += 1;
      que.push(node);
    }
  }
  vector<int>::iterator max = max_element(incoming.begin(), incoming.end());
  int index = max - incoming.begin();
  cout << index << "\n" << *max;
}
