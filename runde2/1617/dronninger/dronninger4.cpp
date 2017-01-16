#include <iostream>
#include <algorithm>
#include <cmath>

int main() {
  long long S, R, K;  //størrelse, koordinatinput
  int N, truede = 0;  //antall brikker, truede
  std::cin >> S >> N;
  if (N==0 || N==1 || S==1) { //ingen truede dersom ingen brikker eller bare 1 brikke/rute
    std::cout << 0 << std::endl;
    return 0;
  }
  int rad[N];
  int kolonne[N];
  bool truet[N] = {false};


  for (size_t i = 0; i < N; i++) {  //input koordinatene
    std::cin >> R >> K;
    rad[i] = R;
    kolonne[i] = K;
    truet[i] = false;
  }

  for (size_t i = 0; i < N; i++) {
    if (!truet[i]) {
      for (size_t j = 0; j < N; j++) {
        if (rad[i]==rad[j] && kolonne[i]!=kolonne[j]) {//enten kolonne- eller radkoordinater må være like, ikke begge
          truet[i] = true;
          truet[j] = true;
          break;
        } else if (rad[i]!=rad[j] && kolonne[i]==kolonne[j]){
          truet[i] = true;
          truet[j] = true;
          break;
        }
      }

      if (!truet[i]) {
        for (size_t j = 0; j < N; j++) {
          if (rad[i]!=rad[j] && kolonne[i]!=kolonne[j]) {
            if (abs(rad[i]-rad[j])==abs(kolonne[i]-kolonne[j])) {
              truet[i] = true;
              truet[j] = true;
            }
          }
        }
      }
    }
  }

  std::cout << std::count(truet, truet+N, true) << std::endl;
  return 0;
}
