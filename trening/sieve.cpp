#include <iostream>
#include <cstring>

using namespace std;

int main(){
  long long N;
  cin >> N;
  bool prime[N+1];
  memset(prime, 1, sizeof prime);

  long long currentPrime = 2;
  long long primeSum = 0;

  while (currentPrime<=N) {
    if (!prime[currentPrime]) {
      currentPrime++;
      continue;
    }
    for (size_t i = 2; i*currentPrime <= N; i++) {
      prime[i*currentPrime] = false;
    }
    currentPrime++;
  }

  for (size_t i = 2; i <= N; i++) {
    if (prime[i]) {
      primeSum += i;
      cout << i << " ";
    }
  }
  cout << "\n sum of all primes including input: " << primeSum;
}
