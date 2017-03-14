#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
  int n;
  string input;
  cin >> n;
  bool lys[n];

  memset(lys, 0, sizeof lys);

  for (size_t i = 0; i < n; i++) {
    cin >>input;
    if (input=="PA") {
      lys[i] = true;
    }
  }

  return 0;
}
