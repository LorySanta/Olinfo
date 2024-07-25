#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    //creo la adjiacenty list
    int N, A, B;
    cin >> N >> A >> B;
    vector<vector<int>> adjlist(N + 1);
    //collego le lapadine di tipo 1 a una ipotetica lampadina N

    for (int i = 0; i < A; i++) {
        int l;
        cin >> l;
        adjlist[N].push_back(l); // non serve segnarlo in modo orientato
    }

    for (int i = 0; i < B; i++) {
        int a, b; cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
        //serve inserirli in modo orientato
    }

    // aggiungi codice...
   
    //faccio una dfs e mi segno tutte le distanze -> djikstra's semplificato
    vector<int> distanza(N+1, (int)(1e9)); //segno la distanza
    vector<bool> visto(N+1);
    queue<int> Q;
    Q.push(N); //parte da n e calcola la distanza di tutte da lui
    distanza[N] = 0;
    while (!Q.empty()) {
        int i = Q.front();
        Q.pop();
        visto[i] = true;
        for (int u:adjlist[i]) {
            if (visto[u]) continue;
            Q.push(u);
            distanza[u] = min(distanza[i] + 1, distanza[u]);
        }
    }

    int idx; int num = 0;
    for (int i = 0; i<N; i++) {
        if (num < distanza[i]) {
            idx = i;
            num = distanza[i];
        }
    }
   
    cout << "Case #" << t << ": " << idx << " " << num << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }
    return 0;
}
