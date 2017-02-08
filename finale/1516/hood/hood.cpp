#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

bool wayToSort(int A, int B){
  return A>B;
}

int main() {
  int P, N, F;
  std::deque<int> person;
  for (size_t i = 0; i < N; i++) {
    std::cin >> F;
    person.push_back(F);
  }
  std::sort(person, wayToSort);

  for (size_t i = 0; i < N; i++) {
    if (person[i]>P) {
      person[i].
    }

    for (size_t j = 0; j < N-i; j++) {
       else {

      }
    }
  }
  return 0;
}
