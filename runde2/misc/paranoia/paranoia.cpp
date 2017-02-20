#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
  int X, Y, M, N; //basic input
  int antall;
  double coords[4];  //input for pic coords
  double inp, inp2;
  char shape; //shape of pics
  cin >> X >> Y >> M >> N;  //input various shit
  double x,y;  //coords of installations
  double pics[M][4];  //coords of pics
  double r, s1, s2, s3, s4; //vars for calculations

  for (size_t i = 0; i < M; i++) {  //inputting all image coords
    cin >> shape;
    if (shape=='r') { //rectangles
      for (size_t j = 0; j < 4; j++) {
        cin >> inp;
        pics[i][j] = inp;
      }
    } else {
      for (size_t j = 0; j < 3; j++) {  //circles
        cin >> inp;
        pics[i][j] = inp;
      }
      pics[i][3] = -1;
    }
  }

  for (size_t i = 0; i < N; i++) {  //input for installations
    antall = 0;
    cin >> x >> y;
    for (size_t j = 0; j < M; j++) {  //looping through all pics for every installation
      if (pics[j][3]==-1) {
        r = pics[j][2] * pics[j][2];
        s1 = pow(pics[j][0] - x, 2);
        s2 = pow(pics[j][1] - y, 2);
        if ((s1+s2)<r) {  //fits in equation (x-x_1)²+(y-y_1)²<r²
          ++antall;
        }
      } else {
        s1 = pics[j][0];
        s2 = pics[j][1];
        s3 = pics[j][2];
        s4 = pics[j][3];
        if ((x>s1)&&(x<s3)&&(y>s2)&&(y<s4)) {
          ++antall;
        }
      }
    }
    cout << antall;
  }
  return 0;
}
