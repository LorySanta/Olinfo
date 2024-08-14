#include <bits/stdc++.h>
using namespace std;


//la sparse table costruisce in O(N), ha queries in O(1). Funziona nei monoidi tali che a*a = a. [gcd, min, max...]
struct sparsetable {
    vector<vector<int>> st;


    //costruttore
    sparsetable(vector<int> V) {
        int N = V.size(); int L = log2(N) + 1;
        vector<vector<int>> aus(L, vector<int> (N));
        for (int i = 0; i<N; i++) aus[0][i] = V[i];
        for (int j = 1; j<L; j++) {
            int pw = 1 << (j-1);
            for (int i = 0; i<N; i++) {
                if (i+2*pw>N) continue;
                aus[j][i] = min(aus[j-1][i], aus[j-1][i+pw]);
            }
        }
        st = aus;
    }


    //processa la query
    int query(int a, int b) {
        //troviamo la minima potenza di due
        b++; //serve perchè sennò è [a, b[
        int pw2 = 1 << (int)(log2(b-a));
        return min(st[(int)(log2(b-a))][a], st[(int)(log2(b-a))][b-pw2]);
    }
};


int main() {
    int N, Q; cin >> N >> Q;
    vector<int> V(N);
    for (int i = 0; i<N; i++) cin >> V[i];
    //buildo la st
    sparsetable ST = sparsetable(V);
    //itero le queriess
    for (int i = 0; i<Q; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        cout << ST.query(a, b) << endl;
    }


    return 0;
}
