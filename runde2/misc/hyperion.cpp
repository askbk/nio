#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct nodeList{
  int y, x, distance;
  nodeList(_y, _x, _distance){
    y = _y;
    x = _x;
    distance = _distance;
  }
  bool operator< {
    return
  }
}

int main() {
  int X, Y;
  cin >> X >> Y;
  char map_array[Y][X];
  bool visited[Y][X];
  memset(visited, 0, sizeof visited);

  for (size_t i = 0; i < Y; i++;) {
    for (size_t j = 0; j < X; j++) {
      char inp;
      cin >> inp;
      map_array[i][j] = inp;
      if(inp=='#'){
        visited[i][j] = true;
      } else if(inp=='S'){
        pair<int, int> start = make_pair(i, j);
        visited[i][j] = true;
      } else if(inp =='M'){
        pair <int, int> slutt = make_pair(i, j);
      }
    }
  }

  priority_queue<int> priqu;

  vector< vector<int> > distance;

  distance[].

  while (!priqu.empty()) {
    /* code */
  }

  return 0;
}
