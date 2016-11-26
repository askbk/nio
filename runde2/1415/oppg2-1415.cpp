#include <iostream>
#include <array>

int main(int argc, char const *argv[]) {
  int K;  //antall stasjoner
  int N;  //antall personer som ønsker å reise med toget
  int A;  //midlertidig variabel for start av strekning
  int B;  //midlertidig variabel for slutt
  int bill = 1; //antall billetter
  std::cin >> K;
  std::cin >> N;
  int AB [N][2];

  for (int i = 0; i < N; i++) { //leser inn personer
    std::cin >> A >> B;
    AB[i][0] = A;
    AB[i][1] = B;
  }

  for (size_t i = 1; i < N; i++) {
    if (AB[0][1]==AB[i][0]) {

    }
  }

  return 0;
}
