#include <bits/stdc++.h>
using namespace std;


struct segmenttree {
    vector<long long> segtr;


    //lo costruisco (operazione sum)
    segmenttree(vector<long long> &V) {
        int L = V.size(); //lo rendo lungo una potenza di 2;
        int N = 1 << ((int)log2(L) + 1);
        while (V.size()<N) V.push_back((long long)(1e9+7)); //aggiungo il neutro del gruppo
        vector<long long> aus(2*N);
        for (int i = N; i<2*N; i++) aus[i] = V[i-N]; //i valori dei nodi più bassi
        for (int i = N-1; i>0; i--) aus[i] = min(aus[2*i], aus[2*i+1]);
        segtr = aus;
    }


    //faccio le queries
    long long query(int a, int b) {
        int N = segtr.size()/2;
        a = a+N; b = b+N; //sistemo gli indici.
        long long m = (int)(1e9) + 7;
        while (!(a>b)) {
            if (a%2 == 1) {
                m = min(m, segtr[a]);
                a = a+1; //lo sposto per salire
            }
            if (b%2 == 0) {
                m = min(m, segtr[b]);
                b = (b-1); //lo sposto per salire
            }
            a/=2; b/=2; // salgo
        }
        return m;
    }


    //query di update
    void update(int i, int u) {
        int N = segtr.size()/2;
        i = i+N;
        segtr[i] = u;
        for (int j=i/2; j>0; j/=2) segtr[j] = min(segtr[2*j], segtr[2*j+1]);
        return;
    }
};




int main() {
    int N, Q; cin >> N >> Q;
    vector<long long> V(N);
    for (int i = 0; i<N; i++) cin >> V[i];


    segmenttree ST = segmenttree(V);


    for (int i = 0; i<Q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            b--;
            ST.update(b, c);
        }
        if (a == 2) {
            b--; c--;
            cout << ST.query(b, c) << endl;
        }      
    }
    return 0;
}
