#include <bits/stdc++.h>
using namespace std;

struct prefixxor {
    vector<int> px;

    prefixxor(vector<int> V) {
        int N = V.size();
        vector<int> aus(N);
        aus[0] = V[0];
        for (int i = 1; i<N; i++) aus[i] = aus[i-1] ^ V[i];
        px = aus;
    }

    int query(int a, int b) {
        if (a == 1) return px[b-1];
        a--; b--;
        return px[b]^px[a-1];
    }
};

int main() {
    int N, Q; cin >> N >> Q;
    vector<int> V(N);
    for (int i = 0; i<N; i++) cin >> V[i];

    prefixxor PX = prefixxor(V);
    for (int i = 0; i<Q; i++) {
        int a, b; cin >> a >> b;
        cout << PX.query(a, b) << endl;
    }
}
