#include <bits/stdc++.h>
using namespace std;

int main() {
    //prendo gli input
    int N, X;
    cin >> N >> X;
    vector<int> P(N);
    for (int i = 0; i<N; i++) cin >> P[i];

    //costruisco la DP
    vector<pair<int, int>> dp(1<<N, {N+1, 0});
    dp[0] = {1, 0}; //una corsa vuota

    //itero sui subset
    for (int i = 0; i< (1<<N); i++) {
        for (int p = 0; p<N; p++) {
            if (i & (1<<p)) {
                auto x = dp[i^(1<<p)]; //x equivale alla dp del set S\p
                if (x.second + P[p] <= X) {
                    x.second += P[p];
                } 
                else {
                    x.first++;
                    x.second = P[p];
                }
            dp[i] = min(x, dp[i]); // vede qual è il migliore
            }
        }
    }

    //siamo interessati a quello con n-1 "1", che si ottiene con: (1<<N)-1
    cout << dp[(1<<N)-1].first << endl;
    return 0;
}
