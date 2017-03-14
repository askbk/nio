#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int pris[n];
  int currentMin, currentMax, currentEnergy = 0;
  int sum = 0;

  currentMin = 100000;
  currentMax = -100000;

  for (size_t i = 0; i < n; i++) {
    cin >> pris[i];
  }

  for (size_t i = 0; i < n; i++) {
    if (i==0) { //dersom første
      if (pris[i]<pris[i+1]) {
        sum -= 1000 * pris[i];  //kjøp dersom lokalt bunnpunkt
        cout << "kjøpte for " << pris[i] << " sum: " << sum << "\n";
      }
      continue;
    } else if(i==n-1) { //dersom siste
      if (pris[i]>pris[i-1]){ //selg dersom lokalt toppunk
        sum += currentEnergy * pris[i];
        cout << "solgte for " << pris[i] << " sum: " << sum << "\n";
      }
      continue;
    }
    if (pris[i] < pris[i+1] && pris[i] < pris[i-1]) { //lokalt bunnpunkt
      if (currentEnergy < 1000) {
        sum -= (1000-currentEnergy) * pris[i]; //kjøp dersom energi ikke er fullt
        currentEnergy = 1000;
        cout << "kjøpte for " << pris[i] << " sum: " << sum << "\n";
      }
    } else if (pris[i] > pris[i+1] && pris[i] > pris[i-1]) {  //lokalt toppunkt
      if (currentEnergy > 0) {
        sum += currentEnergy * pris[i]; //selg
        currentEnergy = 0;
        cout << "solgte for " << pris[i] << " sum: " << sum << "\n";
      }
    }
  }

  cout << sum;
  return 0;
}
