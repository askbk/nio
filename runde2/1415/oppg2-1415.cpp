#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <ios>
#include <string>

int main(int argc, char const *argv[]) {
  int K;  //antall stasjoner
  int N;  //antall personer som ønsker å reise med toget
  int A;  //midlertidig variabel for start av strekning
  int B;  //midlertidig variabel for slutt
  int bill = 0; //antall billetter
  std::cin >> K;
  std::cin >> N;
  /*int start [N];
  int stop [N];
  int AB [N][2];*/
  std::vector<int> start;
  std::vector<int> stop;

  for (int i = 0; i < N; i++) { //leser inn reisestrekninger
    std::cin >> A >> B;

    start.push_back(A);
    stop.push_back(B);

    /*start[i] = A;
    stop[i] = B;*/
  }

  std::sort(start.begin(), start.end());
  std::sort(stop.begin(), stop.end());

  for (size_t i = 0; i < N; i++) {
    for (size_t j = i; j < N; j++) {
      if (j+1<N) {
        if (stop[i]>=start[j+1]) {
          bill++;
          std::cout << stop[i]<<">="<<start[j+1] << std::endl;
        }
      }
      if (i>=1) {
        if (stop[i-j]<start[j]) {
          std::cout << stop[i-j]<<"<"<<start[j] << std::endl;
          bill--;
        }
      }

    }
  }

  std::cout << bill << std::endl;

  /*std::sort(start.begin(), start.end());
  std::sort(stop.begin(), stop.end());

  for (size_t i = 0; i < N; i++) {
    std::cout << start[i] << ' ' << stop[i] << std::endl;
  }

  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      if (start[i]>stop[j]) {
        bill++;
      } else {
        break;
      }
    }
    if (start[i]!=start[N]) {
      if (start[i]==stop[i+1]) {
        bill--;
      }
    }
    if (stop[i]<start[i+1]) {
      bill++;
    }
  }
  if (bill>N) {
    std::cout << N << std::endl;
  } else {
    std::cout << bill << std::endl;
  }*/


  /*std::sort(AB[0], AB[0] + N);
  std::sort(AB[][])

  for (size_t i = 0; i < N; i++) {
    std::cout << AB[i][0] + " " << AB[i][1] << std::endl;
  }*/

  return 0;
}
