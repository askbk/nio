#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
  int P, N, F, bunn, topp;
  int sum = 0;
  std::vector<int> person;

  std::cin >> P >> N;

  bunn = (N / 2) - 1;
  topp = bunn + 1;

  for (size_t i = 0; i < N; i++) {
    std::cin >> F;
    person.push_back(F);
  }

  std::sort(person.begin(), person.end());

  sum = person[bunn] + person[topp];

  while (sum!=P) {  //mens summen ikke er riktig
    std::cout << sum << '\n';
    if (sum<P) {  //for lite
      if (topp!=(N-1)) {  //topp er ikke på siste element
        ++topp; //flytt topp til høyre
        sum += person[topp];
      } else {
        if (bunn!=0) {  //bunn er ikke på første element
          --bunn; //flytt bunn til venstre
          sum += person[bunn];
        }
      }

    } else {  //for mye
      sum -= person[topp];
      --topp; //flytt topp til venstre
      if (bunn!=0) {  //flytt til venstre dersom bunn ikke er første element
        --bunn;
        sum += person[bunn];
      }
    }
  }
  return 0;
}
