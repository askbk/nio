#include <iostream>
#include <tuple>

int clear(int pos_x, int pos_y, int poso, char kart) {
  switch (poso) {
    case 0:
      if (kart[pos_x][pos_y-1]=='.' || kart[pos_x][pos_y+1]=='M') {
        return 1;
      } else {
        return 0;
      }
    break;
    case 1:
    if (kart[pos_x+1][pos_y]=='.' || kart[pos_x+1][pos_y]=='M') {
      return 1;
    } else {
      return 0;
    }
    break;
    case 2:
    if (kart[pos_x][pos_y+1]=='.' || kart[pos_x][pos_y+1]=='M') {
      return 1;
    } else {
      return 0;
    }
    break;
    case 3:
    if (kart[pos_x-1][pos_y]=='.' || kart[pos_x-1][pos_y]=='M') {
      return 1;
    } else {
      return 0;
    }
    break;
  }
}

int main() {
  int X, Y; //størrelse på kart
  char IN;  //inputvariabel
  std::cin >> X >> Y;
  char kart[X][Y];    //array for kart
  int pos_x, pos_y; //x- og y-posisjoner
  int poso = 0; //orientering. 0 - opp, 1 - høyre, 2 - ned, 3 - venstre
  int M_x, M_y; //kordinater til målet
  int commands = 0; //antall kommandoer

  for (size_t i = 0; i < Y; ++i) {    //input for objekter på kartet
    for (size_t j = 0; j < X; ++j) {
      std::cin >> IN;
      kart[j][i] = IN;
      if (IN == 'S') {  //startposisjonen lagres i posisjonsvariabelen
        pos_x = j;
        pos_y = i;
      } else if (IN == 'M') { //målet lagres
        M_x = j;
        M_y = i;
      }
    }
  }

  while (pos_y != M_y && pos_x != M_x) {
    for (size_t i = 0; i < 4; i++) {
      if (clear(pos_x, pos_y, poso, kart)) {
        /* code */
      }
    }
  }

  return 0;
}
