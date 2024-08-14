#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N, X;
    cin >> N >> X;
    vector<int> V(N);
    for (int i = 0; i<N; i++) cin >> V[i];
    sort(V.begin(), V.end());
    int a = 0; int b = N-1;
    int cont = 0;
    while (!(b<a)) {
        if (V[a]+V[b] > X) {
            cont++;
            b--;
        }
        else {
            cont++;
            a++; b--;
        }
    }


    cout << cont << endl;
    return 0;
}
