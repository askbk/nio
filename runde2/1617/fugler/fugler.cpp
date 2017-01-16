#include <iostream>

int main() {
  int N; //antall mulige farger
  int E; //antall fargeendringer som er mulige

  std::cin >> N >> E;

  int A, B; //fargeendring A til B
  double s; //Sannsynlighet for at fugl med farge A skifter farge til farge B
  double pMatrise[N][N];  //Sannsynlighetsmatrise, verdiene skal ikke endres
  double bMatrise[N][N];  //mellomleddsmatrise ved opphøying
  double uMatrise[N][N];  //Sannsynlighetsmatrise som inneholder sluttresultatene
  double verdi;

   std::cout.precision(8);

  for (size_t i = 0; i < N; i++) { //setter alle verdier til null
    for (size_t j = 0; j < N; j++) {
      pMatrise[i][j] = double(0);
    }
  }

  for (size_t i = 0; i < E; ++i) { //input for alle sannsynligheter
    std::cin >> A >> B >> s;
    pMatrise[A-1][B-1] = s;
  }

  for (size_t i = 0; i < N; i++) { //summen av hver rad må være 1, sett resterende sannsynlighet for farge [i] til rad[i] og kolonne[i]
    double rowSum = double(0);
    for (size_t j = 0; j < N; j++) {
      rowSum += pMatrise[i][j];
    }
    if (rowSum<double(1)) {
      pMatrise[i][i] += double(1) - rowSum;
    }
  }

  int Q;  //antall spørringer
  std::cin >> Q;
  int F;  //hvilken farge fuglen starter med
  int K;  //antall bær fuglen spiser

  for (size_t i = 0; i < Q; i++) {  //gjentar for hver spørring
    std::cin >> F >> K;

    for (size_t i = 0; i < N; i++) {  //setter alle verdier i uMatrise og bMatrise lik verdiene i pMatrise for hver spørring
      for (size_t j = 0; j < N; j++) {
        uMatrise[i][j] = pMatrise[i][j];
        bMatrise[i][j] = pMatrise[i][j];
      }
    }

    for (size_t p = 1; p < K; p++) {  //opphøyer matrisen i K (antall bær som er spist)
      for (int rad = 0; rad < N; rad++) { //
        for (int kol = 0; kol < N; kol++) { //kolonner i matrise 2, rader i matrise 1
          verdi = double(0);
          for (size_t i = 0; i < N; i++) { //
            verdi +=  pMatrise[rad][i] * bMatrise[i][kol];
          }
          uMatrise[rad][kol] = verdi; //endrer på umatrisen.
        }
      }
      for (size_t i = 0; i < N; i++) {  //setter den midlertidige bMatrisen lik uMatrisen
        for (size_t j = 0; j < N; j++) {
          bMatrise[i][j] = uMatrise[i][j];
        }
      }
    }

    for (size_t k = 0; k < N; k++) {  //printer ut resultat for spørringen
      std::cout << uMatrise[F-1][k] << " " << std::fixed;
    }
    std::cout << "\n";
  }
  return 0;
}
