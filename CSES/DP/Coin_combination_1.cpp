#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, x;
    cin >> n >> x;


    vector<int> C(n);
    vector<int> V(x+1, 0);
    for (int i = 0; i<n; i++) cin >> C[i];
    V[0] = 1;


    for (int i = 0; i<x+1; i++) {
        for (int c:C) {
            if (i-c<0) continue;
            else V[i] = (V[i] + V[i-c])%((int)(1e9+7));
        }
    }

    cout << V[x] << endl;
    return 0;
}
