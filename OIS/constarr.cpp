#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = (int)(1e9+7);
vector<ll> V;

vector<ll> convoluzione(vector<ll> &A, vector<ll> &B) {
    int M = A.size();
    vector<ll> Ans(M, 0);
    for (int i = 0; i<M; i++) {
        for (int j = 0; j<M; j++) {
            int x = (i+j+M)%M;
            Ans[x] += ((A[i]%MOD)*(B[j]%MOD))%MOD;
        }
    }
    return Ans;
}

vector<ll> constarr(ll N, int M) {
    //passi base
    if (N == 1) return V;

    //caso generico
    vector<ll> aus, ans;
    aus = constarr(N/2, M);
    ans = convoluzione(aus, aus);
    if (N&1) ans = convoluzione(ans, V);
    
    return ans;
}


int main() {
    ll N, L, R;
    int M, K;
    cin >> N >> M >> L >> R >> K;
    //Creo il vettore che conta in posizione i quante volte compare in [L, R] un numero x : x = i (mod M)
    R = R - L; L %= M; R += L;
    int ausiliaretotassign = (int)((R-L) + 1)/M;
    V.assign(M, ausiliaretotassign);
    int ausiliaresumL = R-L+1 - ausiliaretotassign*M;
    for (int i = L; i<L + ausiliaresumL; i++) V[(i%M)] += 1;
    
    //poi ricorsivamente calcolo la risposta
    vector<ll> risposta = constarr(N, M);

    cout << risposta[K]%MOD << endl; // print the result
    
    return 0;
}
