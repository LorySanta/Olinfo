// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>
using namespace std;

// input data
int N, M, T;

struct edge {
    int to;
    int time;
    bool exp;
    edge(int a, int b, bool e) {
        to = a; time = b; exp = e;
    }
};

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    //implemento la adjiacenty list
    cin >> N >> M >> T;
    vector<vector<edge>> adjlist(N);
    for (int i=0; i<M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        adjlist[a].push_back(edge(b, c, d));
    }
    // faccio djiksta's banale
    priority_queue<pair<int,int>> Q;
    vector<int> dist(N, (int)(1e9));
    vector<bool> visto(N, false);
    dist[0] = 0; Q.push({0,0});
    while(!Q.empty()) {
        int i = Q.top().second; Q.pop();
        if (visto[i]) continue;
        visto[i] = true;
        for (auto [to, time, exp]:adjlist[i]) {
            if (dist[i] + time > T && exp) continue;
            dist[to] = min(dist[to], dist[i]+time);
            Q.push({-dist[to], to});
        }
    }

    if (visto[N-1]) cout << dist[N-1] << endl;
    else cout << -1 << endl;
    return 0;
}
