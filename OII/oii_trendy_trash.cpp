#include <bits/stdc++.h>
using namespace std;

int pulisci(int N, int M, vector<string> S) {
    vector<int> righe1(N, 0);
    vector<int> colonne1(M, 0);
    vector<int> righe0(N, 0);
    vector<int> colonne0(M, 0);
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<M; j++) {
            righe1[i] += (int)S[i][j]-48;
            colonne1[j] += (int)S[i][j]-48;
        }
    }
    for (int i = 0; i<N; i++) righe0[i] = M-righe1[i];
    for (int i = 0; i<M; i++) colonne0[i] = N-colonne1[i];

    int colonnetolte1 = 0; 
    int righetolte1 = 0;
    int colonnetolte0 = 0;
    int righetolte0 = 0;

    int N0 = N; int N1 = N;
    int M0 = M; int M1 = M;

    sort(righe0.begin(), righe0.end()); sort(colonne0.begin(), colonne0.end());
    sort(righe1.begin(), righe1.end()); sort(colonne1.begin(), colonne1.end());

    int continua = 1;


    while (continua) {
        continua = 0;
        for (int i = N1-1; i>=0; i--) {
            if (righe1[i] - colonnetolte1 >= M && M>0) {
                righetolte1++;
                N--;
                N1--;
                continua++;
            }
            else break;
        }
        for (int i = N0-1; i>=0; i--) {
            if (righe0[i] - colonnetolte0 >= M && M>0) {
                righetolte0++;
                N--;
                N0--;
                continua++;
            }
            else break;
        }
        for (int i = M0-1; i>=0; i--) {
            if (colonne0[i] - righetolte0 >= N && N>0) {
                colonnetolte0++;
                M--;
                M0--;
                continua++;
            }
            else break;
        }
        for (int i = M1-1; i>=0; i--) {
            if (colonne1[i] - righetolte1 >= N && N>0) {
                colonnetolte1++;
                M--;
                M1--;
                continua++;
            }
            else break;
        }
    }
    
    return N*M;
}
