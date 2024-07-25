#include <bits/stdc++.h>
using namespace std;

bool check(int x, long long M, int V[], int N) {
    //somma di base
    long long sum = 0;
    for (int i = 0; i<x; i++) sum += V[i];
    
    int it = x-1;
    while (it < N) {
        if (sum > M) return false;
        sum = sum - V[it-x+1] + V[it+1];
        it++;
    }
    return true;
}

int quadri(int N, long long M, int V[]) {
    // Scrivete qui la vostra soluzione
    int k = 0;
    for (int i = 1 << (int)log2(N); i >= 1; i = i/2) {
        if (k+i <= N && check(k+i, M, V, N)) k = k+i;
    }
    return k;
}
