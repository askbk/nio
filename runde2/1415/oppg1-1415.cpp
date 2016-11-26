#include <iostream>
#include <array>

int main() {
  int N;  //antall stiger
  int M;  //antall terningkast
  int A;  //midlertidig variabel for stigestart
  int B;  //midlertidig variabel for stigeslutt
  int martin = 1; //posisjonsvariabler, starter på felt 1
  int lise = 1;
  int nMartin = 0;  //antall kast
  int nLise = 0;
  int kMartin;  //midlertidige variabler for terningkast
  int kLise;
  std::cin >> N;
  std::cin >> M;
  int AB [N][2];

  for (int i = 0; i < N; i++) { //leser inn stiger
    std::cin >> A >> B;
    AB[i][0]=A;
    AB[i][1]=B;
  }

  for (int i = 0; i < M;) { //leser inn kast og sjekker om seier
    if (martin < 100) { //dersom martin er bak 100
      std::cin >> kMartin;

      if (lise<100) {
        martin += kMartin;
      }

      ++nMartin;
      ++i;
    }

    if (i==M) {
      break;
    }

    if (lise < 100) {
      std::cin >> kLise;

      if (martin<100) {
        lise += kLise;
      }

      ++nLise;
      ++i;
    }

    for (int i = 0; i < N; i++) {
      if (martin==AB[i][0]) {
        martin = AB[i][1];
        break;
      }
    }

    for (int i = 0; i < N; i++) {
      if (lise==AB[i][0]) {
        lise = AB[i][1];
        break;
      }
    }
  }
  if (martin>=100) {
    std::cout << "Martin " << nMartin << " " << lise << std::endl;
  } else if (lise>=100) {
    std::cout << "Lise " << nLise + " " << martin << std::endl;
  } else {
    std::cout << martin << " " << lise << std::endl;
  }
  return 0;
}
