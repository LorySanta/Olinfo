#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> P(N);
    vector<int> A(M);
    for (int i = 0; i<N; i++) cin >> P[i];
    for (int i = 0; i<M; i++) cin >> A[i];
    sort(P.begin(), P.end());
    sort(A.begin(), A.end());

    int p = 0, a = 0;
    int ans = 0;
    while (p<N) {
        if (a >= M) break;
        if (P[p] + K >= A[a] && P[p] - K <= A[a]) {
            ans++;
            p++;
            a++;
        }
        else if (P[p] + K < A[a]) p++;
        else if (P[p] - K > A[a]) a++;
    }

    cout << ans << endl;
    return 0;
}
