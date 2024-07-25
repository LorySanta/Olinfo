#include<bits/stdc++.h>
using namespace std;

struct node {
    vector<pair<int,int>> to;
    vector<pair<int,int>> in;
};

int solve(int N, int M, int T, int* S, int* E) {
    vector<node> G(N);
    for (int i = 0; i<M; i++) {
        G[S[i]].to.push_back({E[i], 1});
        G[E[i]].in.push_back({S[i], INFINITY});
    }

    vector<bool> visto(N, false);
    vector<int> distance(N, (int)(1e9)+7);
    priority_queue<pair<int,int>> Q;
    Q.push({0,0}); distance[0] = 0;
    while (!Q.empty()) {
        int atm = Q.top().second; Q.pop();
        if (visto[atm]) continue;
        visto[atm] = true;
        if (distance[atm] < T) {
            for (auto [edge, dist] : G[atm].to) {
                distance[edge] = min(distance[edge], distance[atm] + dist);
                Q.push({-distance[edge], edge});
            }
        }
        for (auto [edge, dist] : G[atm].in) {
            dist = max(T - distance[atm]+1, 1);
            distance[edge] = min(distance[edge], distance[atm] + dist);
            Q.push({-distance[edge], edge});
        }
    }

    if (!visto[N-1]) return -1;
    return distance[N-1];
}
