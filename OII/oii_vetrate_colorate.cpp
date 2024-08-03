#include <bits/stdc++.h>
using namespace std;

bool ordina(int N, vector<int> V, vector<int> &L) {
    //faccio il controllo
    int check = -1;
    int ptr = 0;
    int l = 1;
    if (V[0] < V[1]) {
        L.push_back(l);
        l = 0;
    } 
    while (ptr<N-2) {
        l++;
        ptr++;
        if (V[ptr] < V[ptr+1]) {
            L.push_back(l);
            l = 0;
        }
    }
    L.push_back(l+1);
    //sorto
    int at = 0;
    for (int i = 0; i<L.size(); i++) {
        vector<int> aus(L[i]);
        for (int j = 0; j<L[i]; j++) {
            aus[j] = V[at+j];
        }
        sort(aus.begin(), aus.end());
        for (int j = 0; j<L[i]; j++) {
        V[at+j] = aus[j];
        }
        at+=L[i];
    }
    //vedo se è true/false
    for (int i = 0; i<N-1; i++) {
        if (V[i]>V[i+1]) return false;
    }

    return true;
}
