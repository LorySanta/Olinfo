#include <bits/stdc++.h>
#include <stdio.h>
#include <assert.h>
using namespace std;

#define MAXK 10000
#define MAXM 100000

int compra(int N, int M, int K, int supermercati[], int da[], int a[]) {
    // Mettete qui il codice della soluzione
    //implemento il grafo
    vector<vector<int>> grafo(N+1);
    for (int i = 0; i<M; i++) {
        grafo[da[i]].push_back(a[i]);
        grafo[a[i]].push_back(da[i]);
    }


    //bfs da pietro
    vector<int> distpietro(N+1);
    vector<int> vistopietro(N+1, false);
    vector<bool> distaggp(N+1, false);


    queue<int> Q;
    Q.push(1); distpietro[1] = 0;
    while (!Q.empty()) {
        int atm = Q.front(); Q.pop();
        if (vistopietro[atm]) continue;
        vistopietro[atm] = true;
        for (auto i:grafo[atm]) {
            Q.push(i);
            if (distaggp[i]) continue;
            distpietro[i] = distpietro[atm]+1;
            distaggp[i] = true;
        }
    }


    //bfs da nonna
    queue<int> Q2;
    vector<int> distnonna(N+1);
    vector<bool> vistononna(N+1, false);
    vector<int> distaggn(N+1, false);


    Q2.push(N); distnonna[N] = 0;
    while (!Q2.empty()) {
        int atm = Q2.front(); Q2.pop();
        if (vistononna[atm]) continue;
        vistononna[atm] = true;
        for (auto i:grafo[atm]) {
            Q2.push(i);
            if (distaggn[i]) continue;
            distnonna[i] = distnonna[atm]+1;
            distaggn[i] = true;
        }
    }


    int ans = (int)(1e9+7);
    for (int i = 0; i<K; i++) {
        ans = min(ans, (distpietro[supermercati[i]] + distnonna[supermercati[i]]));
    }
   
    return ans;
}




int supermercati[MAXK], da[MAXM], a[MAXM];


int main() {
    FILE *fr, *fw;
    int N, M, K, i;


    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(3 == fscanf(fr, "%d%d%d", &N, &M, &K));
    for(i=0; i<K; i++)
        assert(1 == fscanf(fr, "%d", &supermercati[i]));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d%d", &da[i], &a[i]));
    fprintf(fw, "%d\n", compra(N, M, K, supermercati, da, a));
    fclose(fr);
    fclose(fw);
    return 0;
}
