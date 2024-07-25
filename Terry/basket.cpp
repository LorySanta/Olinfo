// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <bits/stdc++.h>
using namespace std;

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;

        vector<int> A(N);
        vector<int> B(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];

        int ans = 0;

        // INSERISCI IL TUO CODICE QUI
        sort(A.begin(), A.end()); sort(B.begin(), B.end());
        int a = 0, b = 0;
        while (a != N && b != N) {
            if (A[a] == B[b]) {
                ans++;
                a++; 
                b++;
            }
            if (A[a] > B[b]) b++;
            if (A[a] < B[b]) a++;
        }

        cout << "Case #" << test << ": ";
        cout << ans << endl;
    }

    return 0;
}

