#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> price;

int lowerSearch(int n){
  int iterator = N/2, upper = N-1, lower = 0;
  while(price[iterator]!=M){
    if (price[iterator]<M) {
      lower = iterator;
    } else {
      upper = iterator;
    }
    iterator = (upper+lower)/2;
    cout << iterator << "\n";
    if (price[iterator] == M) {
      cout << "høvelig: " << price[iterator];
    }
  }
  return iterator;
}

int main() {
  cin >> N;
  price.resize(N);
  for(int i = 0; i<N; ++i){
    cin >> price[i];
  }
  sort(price.begin(), price.end());
  cin >> M;


  return 0;
}
