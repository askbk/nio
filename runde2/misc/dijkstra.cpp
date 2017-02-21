#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 1000000000
typedef pair < int , int > ii;

int main(int argc, char const *argv[]) {
  int V, E;
  cout << "Antall noder og kanter:";
  cin >> V >> E;
  cout << "\n";
  vector< vector< ii > > kant;

  for (size_t i = 0; i < V; i++) {
    int a,b,c;
    cout << "skriv inn to noder og vekten av avstand mellom dem: \n";
    cin >> a >> b >> c;
    kant[a].push_back(ii(c, b));
    kant[b].push_back(ii(c, a));
    cout << "\n";
  }

  cout << "Skriv inn startnode og sluttnode: \n";

  int start, slutt;
  cin >> start >> slutt;

  priority_queue que;

  return 0;
}
