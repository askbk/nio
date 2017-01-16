#include <iostream>

int main() {
  int aMatrix[3][3];
  int bMatrix[3][3];
  int uMatrix[3][3];
  int startMatrix[3] = {0, 1, 0};
  int ferdig[3] = {0, 0, 0};

  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      aMatrix[i][j] = i+1;
      bMatrix[i][j] = i+1;
      uMatrix[i][j] = i+1;
    }
  }

  std::cout << "matrix product of: " << std::endl;
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      std::cout << aMatrix[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      std::cout << bMatrix[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";


  for (size_t p = 0; p < 3; p++) {
    for (int rad = 0; rad < 3; rad++) { //
      for (int kol = 0; kol < 3; kol++) { //kolonner i matrise 2, rader i matrise 1
        int verdi = 0;
        for (size_t i = 0; i < 3; i++) { //
          verdi +=  aMatrix[rad][i] * bMatrix[i][kol];
        }
        uMatrix[rad][kol] = verdi;
      }
    }
    for (size_t i = 0; i < 3; i++) {
      for (size_t j = 0; j < 3; j++) {
        bMatrix[i][j] = uMatrix[i][j];
      }
    }
  }

  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      std::cout << uMatrix[i][j] << " ";
    }
    std::cout << "\n";
  }

  for (size_t i = 0; i < 3; i++){
    std::cout << startMatrix[i] << " ";
  }

  std::cout << "\n";

    for (int kol = 0; kol < 3; kol++) { //kolonner i matrise 2, rader i matrise 1
      int verdi = 0;
      for (size_t i = 0; i < 3; i++) { //
        verdi +=  startMatrix[i] * uMatrix[i][kol];
      }
      ferdig[kol] = verdi;
    }

  for (int i = 0; i < 3; ++i) {
    std::cout << ferdig[i] << " ";
  }

  return 0;
}
