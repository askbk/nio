#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int P = 0;
  long long e = 0, A = 0, energyLevel = 0, maxEnergy = 0, a = 0, b = 0;
  long long oldB = 0;
  vector<long long> distance;
  vector<long long> energy;
  vector<long long> startP;

  cin >> P;

  for (int i = 0; i < P; ++i){
    cin >> a >> b >> e;
    startP.push_back(a);
    energy.push_back(e);
    if (i==0) {
      distance.push_back(e);
      oldB = b;
      continue;
    }
    distance.push_back(e-(a-oldB));
    oldB = b;
  }
  cin >> A >> energyLevel;

  vector<long long>::iterator it = upper_bound(startP.begin(), startP.end(), A);
  long long index = it - startP.begin();
  energyLevel += energy[index];
  maxEnergy = energyLevel;
  distance[index] -= energy[index];

  for(size_t i = index; i < P; ++i){
    energyLevel += distance[i];
    distance[i] -= energy[i];
    cout << distance[i] << "\n";
    if(energyLevel<0){
      break;
    }
    if (energyLevel>maxEnergy) {
      maxEnergy = energyLevel;
    }
  }

  cout << maxEnergy;
}
