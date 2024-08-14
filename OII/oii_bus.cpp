#include <bits/stdc++.h>
using namespace std;

struct node {
    vector<pair<int, int>> adjlist; //from [Node] to [first pair], weight:[ssecond pair]
};

int pianifica(int N, int L, vector<vector<int>> F) {
    vector<node> G(N);

    //implemento il nodo
    for (int l = 0; l<N; l++) {
        //salvo F[l][0] 
        G.push_back({}); //aggiungo un nodo
        int atm = G.size() - 1;
        G[atm].adjlist.push_back({F[l][0], 0});
        G[F[l][0]].adjlist.push_back({atm, 1});
        for (int i = 1; i<F.size(); i++) {
            G.push_back({});
            int to = G.size()-1;
            G[atm].adjlist.push_back({to, 0});
            G[to].adjlist.push_back({F[l][i], 0});
            G[F[l][i]].adjlist.push_back({to, 1});
            to = atm;
        }
    }

    for (int i = 0; i<G.size(); i++) {
        cout << " G[i] = {";
        for (auto [to, w] : G[i].adjlist) {
            cout << "( " << to << ", " << w << ")" << "; ";
        }
        cout << endl;
    }
    return 42;
}


int main() {
    ios_base::sync_with_stdio(false);
    // se preferisci leggere e scrivere da file ti basta decommentare le seguenti due righe:
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N, L;
    cin >> N >> L;

    vector<vector<int>> F(L);
    for (int i = 0; i < L; i++) {
        int K;
        cin >> K;
        F[i].resize(K);
        for (int j = 0; j < K; j++) {
            cin >> F[i][j];
        }
    }

    cout << pianifica(N, L, F) << endl;

    return 0;
}
