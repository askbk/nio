
pMatrix[N][N]; //inneholder sannsynlighetene
aMatrix[N][N]; //en av de midlertidige matrisene
bMatrix[N][N];
int k = exp2(floor(log2(k)));
int logK = floor(log2(k));
int rest = K - k;

while (rest!=0) {
  for (size_t i = 0; i < logK; i++) {
    //multiplikasjon av midlertidig aMatrix=pMatrix logK ganger
  }
}




power(double I[][], k){
  double A, B, C;
  if (k=1) {
    return I;
  } else if (k>2) {
    n = exp2(floor(log2(k)));
    m = k - n;
    A = power(I, n);
    if (m>1) {
      B = power(I, m);
    } else if (m==1){
      B = I;
    }
    C = A x B;
    return C;
  } else if (k==2){
    A = IxI;
    return B;
  }
}
