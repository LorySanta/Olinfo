#include <bits/stdc++.h>
using namespace std;

long long riciclo(int N, int M, vector<int> T, vector<int> P) {
    //costruisco il vettore delle potenze in modo greedy
    vector<long long> pw2(32, 0);
    for (int j = 0; j<32; j++) {
        for (int i = 0; i<N; i++) {
            if (T[i]&1) {
                pw2[j] += 1;
            }
            T[i] = T[i]/2;
        }
    }
    //costruisco i nuovi trattori
    for (int i = 0; i<32; i++) {
      pw2[i] = pw2[i] * (1<<i);
    }
    //prendo in modo greedy i numeri
    long long count = 0;
    int i = 0;
    for (int i = 0; i<32; i++) {
      for (int j=0;j<=i && j<M;j++) {
        long long tolgo = min((long long)P[j], pw2[i]/(1<<j));
        count += tolgo;
        P[j] -= tolgo;
        pw2[i] -= tolgo*(1<<j);
      }
    }

    return count;
}
