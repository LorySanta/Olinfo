#include <bits/stdc++.h>
using namespace std;

int main() {
    //creazione variabili
    int N; cin >> N;
    char V[N][N];
    for (int i = 0; i<N; i++) {
        for (int p = 0; p<N; p++) cin >> V[i][p];
    }

    //creo il vettore risposta
    int P[N][N];
    P[0][0] = 1; //passo base
    if (V[0][0] == '*') P[0][0] = 0;
    for (int i = 1; i<N; i++) {
        if (V[0][i] == '*') P[0][i] = 0;
        else P[0][i] = P[0][i-1];
    }
    for (int i = 1; i<N; i++) {
        if (V[i][0] == '*') P[i][0] = 0;
        else P[i][0] = P[i-1][0];
    }

    //eseguo la dp in O(N^2)
    for (int i = 1; i<N; i++) {
        for (int j = 1; j<N; j++) {
            if (V[i][j] == '*') P[i][j] = 0;
            else {
                P[i][j] = (P[i-1][j] + P[i][j-1])%((int)(1e9+7));
            }
        }
    }
    cout << P[N-1][N-1] << endl;
    return 0;
}
