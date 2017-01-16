#include <iostream>
#include <algorithm>

int knapSack(int W, int wt[], int val[], int N){
  if (N==0 || W==0) {   //dersom det er 0 vekter eller 0 kapasitet
    return 0;
  }
  if (wt[N-1] > W) {  //dersom vekt N er større enn kapasiteten, kan man utelukke den
    return knapSack(W, wt, val, N-1);
  } else {
    return std::max(val[N-1] + knapSack(W-wt[N-1], wt, val, N-1),
                    knapSack(W, wt, val, N-1)
                  );
  }
}

int main() {
  int W, N, curW, T1, T2;

  std::cin >> W >> N;

  int val[N], wt[N];

  for (size_t i = 0; i < N; i++) {
    std::cin >> T1 >> T2;
    val[i] = T1;
    wt[i] = T2;
  }

  std::cout << knapSack(W, wt, val, N) << std::endl;
  return 0;
}
