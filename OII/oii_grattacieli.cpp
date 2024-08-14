#include <bits/stdc++.h>
using namespace std;


long long costruisci(int N, int M, vector<long long>& H, vector<int>& A, vector<int>& B, vector<int>& C) {
    //costurisco il grafo
    vector<vector<pair<int, long long>>> G(N+1);
    for (int i = 0; i<M; i++) G[A[i]].push_back({B[i], C[i]});
    for (int i = 0; i<N; i++) G[N].push_back({i, H[i]});


    //faccio djikstra's
    vector<long long> dist(N+1, (long long)1e16);
    vector<bool> visto(N+1, false);
    priority_queue<pair<long long, int>> Q;
    dist[N] = 0;
    Q.push({0, N});
    while (!Q.empty()) {
        int atm = Q.top().second; Q.pop();
        if (visto[atm]) continue;
        visto[atm] = true;
        for (auto [to, w] : G[atm]) {
            if (dist[to] > dist[atm] + (long long)w) dist[to] = dist[atm]+ (long long)w;
            Q.push({-dist[to], to});
        }
    }


    //sommo tutti
    long long sum = 0;
    for (int i = 0; i<N; i++) sum += dist[i];
    return sum;
}
