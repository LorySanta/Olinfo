#include <bits/stdc++.h>
using namespace std;

long long jos(long long N) {
    if (N == 1) return 1;
    if (N%2 == 0) return (2*jos(N/2) - 1);
    else return (2*jos((N)/2) + 1);
}

int main() {
    long long Q; long long N;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        //Qui la risposta
        cin >> N;
        long long sol = jos(N);
        cout << sol << endl;
    }
    return 0;
}
