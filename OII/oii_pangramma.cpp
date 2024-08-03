#include <bits/stdc++.h>
using namespace std;

const int MOD = 46337;
vector<int> inversi(MOD, 69000);

int fastexp(int a, int exp) {
    if (exp == 1) return a;
    long long x = fastexp(a, exp/2);
    x = (x*x)%MOD;
    if (exp&1) x = (x*a)%MOD;
    return x;
}

int inverso(int a, int exp) { 
    if (inversi[a]!=69000) return inversi[a];
    int inv = fastexp(a, exp);
    inversi[a] = inv;
    return inv;
}

int conta(int N, int K, vector<int>& V) {
    //trovo la lunghezza di un minimo
    vector<int> count(K,0);
    int L = 1e9;
    int tot = K;
    int itlast = 0;
    int l = 0;
    for (int i = 0; i<N; i++) {
        if (tot>0 && count[V[i]] == 0) tot--;
        count[V[i]] += 1;
        l++;
        while (count[V[itlast]] > 1) {
            count[V[itlast]]--;
            itlast++;
            l--;
        }
        if (tot==0) L = min(L,l);
    }
    if (tot>0) return 0;
    //Itero su tutti i minimi
    count.assign(K, 0);
    int sum = 0;
    tot = K;
    for (int i = 0; i<L; i++) {
        if (count[V[i]] == 0) tot--;
        count[V[i]] += 1;
    }
    
    int p = 1;
    for (auto c : count) {
        if ((c%MOD)==0) continue;
        p = (p*c)%MOD;
    }
    
    if (tot == 0) sum += p;
    for (int i = L; i<N; i++) {
        if (V[i-L] == V[i]) {
            if (tot == 0) sum = (sum+p)%MOD;
            continue;
            }
        if (count[V[i-L]] == 1) tot++;
        count[V[i-L]]--;
        count[V[i]]++;
        if (count[V[i]] == 1) tot--;
        if ((count[V[i-L]])%MOD > 0) p = (((p*inverso((count[V[i-L]]+1)%MOD, MOD-2))%MOD)*count[V[i-L]])%MOD;
        if ((count[V[i]])%MOD > 1) p = (((p*inverso((count[V[i]]-1)%MOD, MOD-2))%MOD)*count[V[i]])%MOD;
        if (tot == 0) sum = (sum+p)%MOD;
    }
    return (sum%MOD);
}
