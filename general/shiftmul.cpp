#include <bits/stdc++.h>
using namespace std;
vector<int> shiftmul(vector<int> A, vector<int> B, long long D, int N) {
    long long a, b;
    for (int i = 0; i<N; i++) {
        a = (long long)(A[i]);
        b = (long long)(B[((N-D+i)%N)]);
        A[i] = (int)((a*b)%((long long)(1e9+7)));
    }
    return A;
}

vector<int> rec(vector<int> A, long long D, int N, int K) {
    if (K == 1) return A;
    vector<int> S = A;

    A = rec(A, D, N, K/2);
    A = shiftmul(A, A, (D*(K/2))%N, N);

    if ((K%2) == 0) return A;
    A = shiftmul(A, S, (D*(K-1))%N, N);
    return A;
}

vector<int> execute(int N, int K, int D, vector<int> A) {
    long long d = D;
    A = rec(A, d, N, K);
    return A;
}
