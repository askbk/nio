#include <iostream>

using namespace std;

long long binom(long long n, long long r){
  if ( r > n /2) r = n-r;

  long long ans = 1;
  for ( long long i = n; i > n - r; i--) {
    ans *= i;
    ans /= n - i;
  }
  return ans;
}

int main(){
  int n;
  cin >> n;
  cout << binom (n-1 , 4) << endl;
  return 0;
}
