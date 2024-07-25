#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>


using namespace std;
int P1 = 0, P2 = 0, P3 = 0, P4 = 0;


//confronto 2 stringhe;
bool conf(string &S1, string &S2, int M, int x1, int x2) {
    if (x1+M > S1.size() || x2+M >S2.size()) return false;
    for (int i = 0; i<M; i++) {
        if (S1[x1+i] != S2[x2+i]) return false;
    }
    return true;
}
//recursion
void search(string &S1, string &S2, string &S3, string &S4, int M, int p1, int p2, int p3, int p4, int t) {
    //tutte uguali
    if (conf(S1, S2, M, p1, p2) && conf(S1, S3, M, p1, p3) && conf(S1, S4, M, p1, p4)) {
        P1 = p1; P2 = p2, P3 = p3; P4 = p4;
        return;
    }
    //prime 3 uguali
    else if (conf(S1, S2, M, p1, p2) && conf(S1, S3, M, p1, p3)) {
        if (p4+M >= S4.size()) {
            search(S1, S2, S3, S4, M, p1+1, 0, 0, 0, t);
            return;
        }
        else {
            search(S1, S2, S3, S4, M, p1, p2, p3, p4+1, t);
            return;
        }
    }
    //prime 2 uguali
    else if (conf(S1, S2, M, p1, p2)) {
        if (p3 + M >= S3.size()) {
            search(S1, S2, S3, S4, M, p1+1, 0, 0, 0, t);
            return;
        }
        else {
            search(S1, S2, S3, S4, M, p1, p2, p3+1, 0, t);
            return;}
    }
    //tutte diverse
    else if (p2+M>=S2.size()) {
        search(S1, S2, S3, S4, M, p1+1, 0, 0, 0, t);
        return;
    }
    else {
        search(S1, S2, S3, S4, M, p1, p2+1, 0, 0, t);
        return;
    }
}


void solve(int t) {
    int N1, N2, N3, N4;
    cin >> N1 >> N2 >> N3 >> N4;


    int M;
    cin >> M;


    string F1, F2, F3, F4;
    cin >> F1 >> F2 >> F3 >> F4;


    // scrivi in queste variabili la risposta
    int p1, p2, p3, p4;


    // RISOLVI QUI IL PROBLEMA!!
    search(F1, F2, F3, F4, M, 0, 0, 0, 0, t);


    cout << "Case #" << t << ": " << P1 << " " << P2 << " " << P3 << " " << P4 << endl;
    P1 = 0; P2 = 0; P3 = 0; P4 = 0;
}


int main() {
    // le seguenti due righe possono essere utili per leggere e scrivere da file


    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    int T;
    cin >> T;


    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}
