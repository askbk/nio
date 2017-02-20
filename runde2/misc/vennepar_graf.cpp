#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  cout  << "Antall  personer: ";
  cin   >> N;
  vector < vector <int> > edge(N);
  int M;
  cout  << "Antall  vennepar: ";
  cin  >> M;
  int a, b;
  while (M--) {
    // tilsvarer  for (int i=0; i<M; i++) , M false  hvis og  bare  hvis M=0
    cout  << "Skriv  indeksene  til  venneparet: ";
    cin  >> a >> b;
    edge[a]. push_back(b);
    edge[b]. push_back(a);
  }
  int A, B;
  cout  << "Skriv  inn  personene  du vil  vite om: ";
  cin  >> A >> B;
  vector <bool > visited(N, false);
  queue < pair <int,int> > que;
// foerste  parameter  er  person ,andre  er  antall  ledd  fra  person  A
  que.push( make_pair(A, 0) );
  visited[A] = true;
  while (!que.empty()) {
    pair <int,int> par=que.front();
    que.pop();
    int person = par.first;
    int dist = par.second;
    if (person  == B) {
      cout  << "Antall  ledd  mellom " << A << " og " << B << " er: " << dist  << endl;
      return 0;
    }
    for (int i = 0; i < edge[person ].size(); i++){
      if (!visited[ edge[person][i]]) {
        que.push(make_pair(edge[person ][i], dist +1));
        visited[ edge[person ][i] ] = true;
      }
    }
  }
  cout  << "Det  finnes  ingen  vennesti  mellom " << A << " og " << B
  << endl;
  return 0;
}
