#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int N, M, Q;
    cin >> N >> M >> Q;

    string S;
    cin >> S;

    // Aggiungi codice se vuoi
    vector<vector<char>> V(M);
    for (int i = 0; i<N; i++) {
        V[0].push_back(S[i]);
    }

    string risposta;

    for (int i = 0; i < Q; i++) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        if (type == 's') {
            // Aggiungi codice...
            V[b].push_back(V[a][V[a].size()-1]);
            V[a].pop_back();
        } 
        else {
            // Aggiungi altro codice...
            risposta.push_back(V[a][b]);
        }
    }

    cout << "Case #" << t << ": " << risposta << endl;
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
