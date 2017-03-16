#include <iostream>
#include <cmath>

using namespace std;

int main(){
  cout.precision(4);
  int N;
  double d, v, u;
  cin >> N;
  for (size_t i = 0; i < N; i++) {
    cin >> d >> v >> u;
    double fastest = 0, shortest = 0;
    fastest = d / u;
    shortest = d / sqrt(u*u - v*v);
    double diff = abs(fastest - shortest);
    if (diff>0.0009 && u!=v && u-v>0) {
      printf("Case %d: %.3f\n", i+1, diff);
    } else {
      cout << "Case " << i+1 << ": can't determine" << "\n";
    }
  }
}
