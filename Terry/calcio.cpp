#include <iostream>
#include <vector>

using namespace std;

void solve(int t) {
    int N, M, K, a, b;
    cin >> N >> M >> K >> a >> b;
    //costruiamo una prefix sum 2D
    vector<vector<int>> calcio(N, vector<int> (M, 0));
    for (int i = 0; i < K; i++) {
        int x, y; cin >> x >> y;
        calcio[x][y]++;
    }

    vector<vector<int>> sum(N, vector<int> (M, 0));
    sum[0][0] = calcio[0][0];

    for (int j = 1; j-M; j++) sum[0][j] = sum[0][j-1] + calcio[0][j];
    for (int i = 1; i<N; i++) sum[i][0] = sum[i-1][0] + calcio[i][0];
    for (int i = 1; i<N; i++) {
        for (int j = 1; j<M; j++) {
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + calcio[i][j];
        }
    }


// aggiungi codice...
    int risposta = sum[a-1][b-1];

    //iteriamo su tutta la prefix sum per cercare il minimo;
    //prima la prima riga
    for (int i = a; i<N; i++) risposta = min(risposta, sum[i][b-1]-sum[i-a][b-1]);
    //poi la prima colonna
    for (int i = b; i<M; i++) risposta = min(risposta, sum[a-1][i]-sum[a-1][i-b]);
    //infine il resto
    for (int i = a+1; i<N; i++) {
        for (int j = b+1; j<M; j++) {
            risposta = min(risposta, (sum[i][j] - sum[i][j-b] - sum[i-a][j] + sum[i-a][j-b]));
        }
    }

    cout << "Case #" << t << ": " << risposta << "\n";
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
