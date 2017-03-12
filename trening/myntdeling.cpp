#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, k; //antall valører, antall beløp, pengebeløp man trenger antall for
int antall[1000]; //antall mynter for verdi i
vector<int> mynter;



int finnAntall(int sum){
  if (sum<0){
    return -1;
  }
  if(antall[sum] != -1){
    return antall[sum];
  }

  int ans = -1;
  for ( int i = 0; i < n ; i ++) {
    int tmp = finnAntall (sum - mynter[i]) ;
    if ( tmp != -1) {
      if ( ans == -1) ans = tmp + 1;
      else            ans = min ( ans , tmp + 1) ;
    }
  }
  return antall[sum] = ans ;
}

int main() {
  int penger;
  cin >> n >> k;

  memset(antall, -1, sizeof antall);

  for (size_t i = 0; i < n; i++) {
    cin >> penger;
    mynter.push_back(penger);
    antall[penger] = 1;
  }

  antall[0] = 0;

  for (size_t i = 0; i < k; i++) {
    cin >> penger;
    cout << finnAntall(penger) << "\n";
  }
  return 0;
}
