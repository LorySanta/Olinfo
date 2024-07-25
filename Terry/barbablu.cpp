#include <bits/stdc++.h>
using namespace std;


struct node {
    vector<pair<int, int>> adjlist;
    bool air;
    int rimair;


    node() {
        adjlist = {};
        air = false;
        rimair = 0;
    }
};


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //Prendo le variabili principali;
    int N, M, C, K;
    cin >> N >> M >> C >> K;
    vector<node> G(N+1);
    //setuppo il grafo
    for (int i = 0; i<K; i++) {
        int a; cin >> a;
        G[a].air = true;
    }
    for (int i = 0; i<M; i++) {
        int a, b, w; cin >> a >> b >> w;
        if (w > 20) continue;
        G[a].adjlist.push_back({b, w});
        G[b].adjlist.push_back({a, w});
    }
    //preparo djikstra's
    vector<int> dist(N+1, (int)(INFINITY));
    vector<bool> visto(N+1, false);
    priority_queue<pair<int,int>> Q;


    G[1].rimair = 20;
    dist[1] = 0;
    Q.push({0, 1});


    while (!Q.empty()) {
        int idx = Q.top().second; Q.pop();
        if (visto[idx]) continue;
        visto[idx] = true;
        for (auto [to, w]: G[idx].adjlist) {


            if (G[idx].rimair - w < 0) continue;
            if (dist[to] > dist[idx]+w) {
                dist[to] = dist[idx] + w;
                G[to].rimair = G[idx].rimair - w;
            }
            if (dist[to] == dist[idx]+w) {
                G[to].rimair = max(G[to].rimair, G[idx].rimair - w);
            }
            if (G[to].air) G[to].rimair = 20;


            Q.push({-dist[to], to});
        }
    }
   
    int ans = dist[C];
    if (!visto[C]) ans = -1;
    cout << ans << endl;


    return 0;
}
