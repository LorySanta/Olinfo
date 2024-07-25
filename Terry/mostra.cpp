#include <bits/stdc++.h>
using namespace std;


const int MAXN = 1000;
const int MAXM = 1000;


int solve() {
    int N, M;
    cin >> N >> M;


    vector<int> V(N), G(M);


    for (int i=0; i<N; i++) {
        cin >> V[i];
    }
    for (int i=0; i<M; i++) {
        cin >> G[i];
    }


    // aggiungi codice...
    vector<vector<int>> dp(M, vector<int> (N));
    vector<vector<bool>> preso(M, vector<bool> (N, false));
    //definiamo la prima riga della matrice dp e del vettore maxcol.
    if (G[0] > V[0]) {
            dp[0][0] = 2;
            preso[0][0] = true;
        }
    else dp[0][0] = 1;
    for (int i = 1; i<N; i++) {
        if (G[0] > V[i]) {
            dp[0][i] = i+2;
            preso[0][i] = true;
        }
        else {
            dp[0][i] = max(dp[0][i-1]+1, i+1);
            if (dp[0][i-1]+1 > i+1) preso[0][i] = preso[0][i-1];
        }
    }


    //eseguiamo la dp
    for (int c = 1; c<M; c++) {
        //la prima colonna
        if (dp[c-1][0] == 2) dp[c][0] = 2;
        else {
            if (G[c] > V[0]) {
                dp[c][0] = 2;
                preso[c][0] = true;
            }
            else dp[c][0] = 1;
        }
        //il resto
        for (int i = 1; i<N; i++) {
            int sopra = dp[c-1][i]; int sin = dp[c][i-1];
            int iposop, iposin; bool presin = false, presop = false;
            // valuta il caso migliore a sinistra
            if (!preso[c][i-1] && G[c] > V[i]) {iposin = sin + 2; presin = true;}
            else {iposin = sin + 1; presin = preso[c][i-1];}
            //valuta il caso migliore sopra
            iposop = sopra;
            presop = false;
            //valuta il migliore tra sinistra e sopra
            if (iposop >= iposin) { dp[c][i] = iposop; preso[c][i] = presop;}
            else { dp[c][i] = iposin; preso[c][i] = presin;}
        }
    }


    //ritorno la risposta
   
    return dp[M-1][N-1];
}


int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:


    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    int T, t;
    cin >> T;


    for (t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
}
