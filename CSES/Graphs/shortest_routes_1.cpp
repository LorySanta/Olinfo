#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, x;
    cin >> n >> x;


    vector<int> C(n);
    vector<int> V(x+1, 1e9);


    for (int i = 0; i<n; i++) cin >> C[i];


    V[0] = 0;


    for (int i = 1; i<(x+1); i++) {
        for (int c = 0; c<n; c++) {
            if (i-C[c] < 0) continue;
            else V[i] = min(V[i], V[i-C[c]] + 1);
        }
    }


    if (V[x] == ((int)(1e9))) cout << -1 << endl;
    else cout << V[x] << endl;
    return 0;
}
