#include <iostream>

int main(){
  double ans, inp;
  int k;
  std::cin >> inp >> k;
  ans = inp;

  while (k > 0) {
    if(k==1){
      ans *= inp;
      --k;
    } else {
      ans *= ans;
      k /= 2;
    }
  }
  std::cout << '\n' << ans << std::endl;
}
