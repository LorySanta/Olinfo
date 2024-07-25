#include <bits/stdc++.h>
using namespace std;
 
struct prefixsum {
    vector<long long> ps; //questo è il vettore prefix
 
    prefixsum(vector<int> V) {  //qui la definisco, uno index
        vector<long long> aus(V.size()+1);
        aus[0] = 0;
        for (int i = 1; i<=V.size(); i++) aus[i] = V[i-1] + aus[i-1];
        ps = aus;
    }
 
    long long sum(int a, int b) { //qui trovo la somma da a a b
        return ps[b+1]-ps[a];
    }
};
 
int main() {
    int N, Q; cin >> N >> Q;
    vector<int> V(N); 
    for (int i = 0; i<N; i++) cin >> V[i];
 
    prefixsum PS = prefixsum(V);
    for (int i = 0; i<Q; i++) {
        int a, b; cin >> a >> b;
        cout << PS.sum(a-1, b-1) << endl;
    }
    
    return 0;
}
