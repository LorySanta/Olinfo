#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int N, K;
    cin >> N >> K;

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    // aggiungi codice...
    sort(C.begin(), C.end());

    //se c'è un solo scaffale si rompe sotto.
    int ans = 0;
    if (K == 1) {
        ans = C[N-1] - C[0]; 
        cout << "Case #" << t << ": " << ans << "\n"; 
        return;
        }

    //calcola la differenza tra due consecutivi e li sorta
    vector<pair<int, int>> consdif(N-1);
    for (int i = 0; i<N-1; i++) {
        consdif[i].first = C[i+1] - C[i];
        consdif[i].second = i+1;
    }
    sort(consdif.begin(), consdif.end());

    //determina la posizione dei salti
    vector<int> pos;
    for (int i = consdif.size() - 1; i >= N-K; i--) {
        pos.push_back(consdif[i].second);
    }
    sort(pos.begin(), pos.end());

    //calcola la risposta
    int it = 0;
    for (int i = 0; i < pos.size(); i++) {
        ans = ans + (C[pos[i]-1] - C[it]);
        it = pos[i];
    }

    //aggiunge l'ultimo scaffale.
    ans = ans + C[N-1] - C[it];

    cout << "Case #" << t << ": " << ans << "\n";
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
