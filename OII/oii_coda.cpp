#include <bits/stdc++.h>
using namespace std;

vector<int> cucina(int N, int K, int X, vector<int> H) {
    vector<int> R(X, 0);
    //creo il vettore pos
    vector<int> pos(X, 0);
    for (int i = 0; i<N; i++) pos[H[i]] += 1;
    //creo i vettori dp, coda
    vector<int> dp(X + 1, 0); 
    //svolgo
    dp[X] = 0; 
    int coda = 0;
    for (int i = X-1; i>=0; i--) {
      int maxcoda = min(K, X-i);
        coda = max(coda - 1, 0);
        dp[i] = dp[i+1] + min(pos[i], maxcoda - coda);
        coda = coda + min(pos[i], maxcoda - coda);
        if (dp[i] > X-i) {
          dp[i] = X - i;
          coda = min(K, X-i);
        }
    }
    for (int i = 0; i<X; i++) R[i] = dp[i];
    return R;
}
