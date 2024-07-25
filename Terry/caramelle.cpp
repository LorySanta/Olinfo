#include <bits/stdc++.h>
using namespace std;


long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, (a%b));
}


int solve(){
    int N;
    cin >> N;
    vector<long long> V(N);
    for(auto &x: V){
        cin >> x;
    }


    long long risposta = V[0];


    // aggiungi codice...
    for (int i = 1; i<N; i++) {
        risposta = risposta*V[i]/gcd(max(risposta, V[i]), min(risposta, V[i]));
    }


    return risposta;
}


int main(){
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
    return 0;
}
