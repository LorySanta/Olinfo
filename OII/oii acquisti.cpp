#include <bits/stdc++.h>
using namespace std;

vector<long long> calcola(int T, int M, vector<long long> S, vector<long long> P) {
    vector<long long> R(M);
    //costurisco le prefixsum
    vector<long long> peso(T);
    peso[0] = 0;
    for (int i = 1; i<T; i++) {
      peso[i] = peso[i-1] + i*S[i];
    }


    vector<long long> trinket(T);
    trinket[0] = S[0];
    for (int i = 1; i<T; i++) {
      trinket[i] = trinket[i-1] + S[i];
    }    


    // scrivi qui il codice della tua soluzione
    for (int m = 0; m < M; m++) {
        //faccio una binarysearch per trovare l'ultimo indice utile
        int k = -1;
        for (long long i = (1ll<<((int)(log2(T)+1))); i>0; i/=2) {
            if (k+i < T && peso[k+i]<=P[m]) k = k+i;
        }
        R[m] = trinket[k];
        if  (k < T-1 && k >= 0) {
          long long pesorimasto = P[m] - peso[k];
          long long rimanenti = min(S[k+1],pesorimasto/(k+1));
          R[m] += rimanenti;
        }
    }


    return R;
}
