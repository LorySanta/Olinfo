#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> V(N);
    for (int i = 0; i < N; i++) cin >> V[i];

    sort(V.begin(), V.end());
    int c = 0;
    for (int i = 0; i<N-1; i++) {
        if (V[i] != V[i+1]) c++;
    }
    c++;
    cout << c << endl;
    return 0;
}
