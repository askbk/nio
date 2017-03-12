#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct state{
  int direction;
  pair< int, int> position;
  int moves;
  state(int _direction, pair<int, int> _position, int _moves){
    direction = _direction;
    position = _position;
    moves = _moves;
  }
};

int main() {
  int X, Y;
  cin >> X >> Y;
  char map_array[Y+2][X+2];
  bool visited[Y+2][X+2];
  memset(visited, 0, sizeof visited);
  queue<state> que;
  pair <int, int> slutt, start;
  int dy[] = {-1, 0, 1, 0};
  int dx[] = {0, 1, 0, -1};

  for (size_t i = 0; i < Y+2; i++) {
    for (size_t j = 0; j < X+2; j++) {
      if (i==0||i==(Y+1)||j==0||j==(X+1)) {
        map_array[i][j] = '#';
        visited[i][j] = true;
        continue;
      }
      char inp;
      cin >> inp;
      map_array[i][j] = inp;
      if(inp=='#'){
        visited[i][j] = true;
      } else if(inp=='S'){
        start = make_pair(i, j);
        que.push(state(0, start, 0));
        visited[i][j] = true;
      } else if(inp =='M'){
        slutt = make_pair(i, j);
      }
    }
  }

  while (!que.empty()) {
    state current = que.front();
    que.pop();
    visited[current.position.first][current.position.second] = true;
    if (current.position==slutt) {
      cout << current.moves;
      break;
    }

    int nxtRad, nxtKol;
    for (size_t i = 0; i < 4; i++) {
      nxtRad = current.position.first + dy[i];
      nxtKol = current.position.second + dx[i];
      if (!visited[nxtRad][nxtKol]) {
        int moves = 0;

        switch (i) {
          case 0:
            if(current.direction==3||current.direction==1)  moves = 1;
            que.push(state(0, make_pair(nxtRad, nxtKol), current.moves + 1 + moves));
          case 1:
            if(current.direction==0||current.direction==2)  moves = 1;
            que.push(state(1, make_pair(nxtRad, nxtKol), current.moves + 1 + moves));
          case 2:
            if(current.direction==1||current.direction==3)  moves = 1;
            que.push(state(2, make_pair(nxtRad, nxtKol), current.moves + 1 + moves));
          default:
            if(current.direction==2||current.direction==0)  moves = 1;
            que.push(state(3, make_pair(nxtRad, nxtKol), current.moves + 1 + moves));
        }
      }
    }
  }
  return 0;
}
