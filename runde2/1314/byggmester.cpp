#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int N, T, p, a;
    vector<int> hus;
    
    cin >> N >> T;
    
    for(int i = 0; i<N; ++i){
        cin >> p;
        hus.push_back(p);
    }
    
    sort(hus.begin(), hus.end());
    
    for(int i = 0; i<T; ++i){
        cin >> a;
        vector<int>::iterator it = lower_bound(hus.begin(), hus.end(), a);
        int index = it - hus.begin();
        
        if(it == hus.end()){   //dersom det ikke finnes hus til høyre
            cout << abs(a-hus[index-1]) << '\n';
        }else{
            if(it == hus.begin()){ //dersom det ikke finnes hus til venstre
                cout << hus[index] << '\n';
            }else{
                cout << min(abs(a-hus[index]), abs(a-hus[index-1]));
            }
        }
    }
    return 0;
}
