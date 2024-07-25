#include <bits/stdc++.h>
using namespace std;


#define MAXN 5000
#define MAXK 5000
#define MAXP 1000000


int mangia(int N, int K, int P[]) {
    // Mettete qui il codice della soluzione
    int risposta = (int)(1e9);
    vector<bool> dp(K, false);
    dp[0] = true;
    for (int i = 0; i<N; i++) {
        for (int j = K-1; j>=0; j--) {
            if (dp[j] && j+P[i] >= K) risposta = min(risposta, j+P[i]);
            if (j-P[i] < K && j-P[i] >= 0 && dp[j-P[i]]) dp[j] = true;
        }
    }
    return risposta;
}




int P[MAXN];


int main() {
    FILE *fr, *fw;
    int N, K, i;


    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &P[i]));


    fprintf(fw, "%d\n", mangia(N, K, P));
    fclose(fr);
    fclose(fw);
    return 0;
}


