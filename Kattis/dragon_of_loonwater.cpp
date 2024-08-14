#include <bits/stdc++.h>
using namespace std;


int main() {
    while (3&1) {
        //le variabili base
        int N, M; cin >> N >> M;
        if (N == 0 && M == 0) break;
        //prendiamo in input i cavalieri
        vector<int> D(N), C(M);
        for (int i = 0; i<N; i++) cin >> D[i];
        for (int i = 0; i<M; i++) cin >> C[i];
        sort(D.begin(), D.end()); sort(C.begin(), C.end());


        int sum = 0;
        bool fine = false;
        int i = 0, j = 0;
        while((i<N && j<M) && !fine) {
            if (C[j] < D[i]) j++;
            else if (C[j] >= D[i]) {
                sum += C[j];
                i++;
                j++;
            }


            if (i==N) fine = true;
        }


        if (fine) cout << sum << endl;
        else cout << "Loowater is doomed!" << endl;


    }
    return 0;
}
