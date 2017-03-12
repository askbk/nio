#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct state{
  int x, y, z, moves;
  state(int _x, int _y, int _z, int _moves){
    x = _x;
    y = _y;
    z = _z;
    moves = _moves;
  }
};

struct triple{
  int x, y, z;
};

int main(){
  int W, H, D;
  int dy[] = {1, 0, 0, -1, 0, 0};
  int dx[] = {0, 1, 0, 0, -1, 0};
  int dz[] = {0, 0, 1, 0, 0, -1};
  char inp;
  queue<state> que; //kø
  cin >> W >> H >> D;
  char map_array[W+2][H+2][D+2];  //kartmatrise
  bool visited[W+2][H+2][D+2];    //holde styr på besøkt
  memset(visited, 1, sizeof visited); //setter alle til besøkt
  memset(map_array, '#', sizeof map_array);

  triple start, slutt;
  cin >> start.x >> start.y >> start.z >> slutt.x >> slutt.y >> slutt.z;
  que.push(state(start.y+1, start.x+1, start.z+1, 0));
  ++slutt.x;
  ++slutt.y;
  ++slutt.z;

  for (size_t i = 1; i < H+1; i++) {
    for (size_t j = 1; j < W+1; j++) {
      for (size_t k = 1; k < D+1; k++) {
        cin >> inp;
        map_array[i][j][k] = inp;
        if (inp=='.') {
          visited[i][j][k] = false;
        }
      }
    }
  }

  while(!que.empty()){
    state current = que.front();
    que.pop();
    if (current.x == slutt.x && current.y == slutt.y && current.z == slutt.z) {
      cout << current.moves;
      break;
    }
    visited[current.y][current.x][current.z] =  true;
    for (size_t i = 0; i < 6; i++) {
      int nxtRad, nxtKol, nxtDyb;
      nxtRad = current.y + dy[i];
      nxtKol = current.x + dx[i];
      nxtDyb = current.z + dz[i];
      if (!visited[nxtRad][nxtKol][nxtDyb]) {
        que.push(state(nxtKol, nxtRad, nxtDyb, current.moves+1));
      }
    }

  }
  if (que.empty()) {
    cout << "Tunnelen kan ikke bygges!";
  }
}
