int tempo_massimo(int N, int a[], int b[]) {
    vector<int> dp(N);
    dp[0] = max(a[0], b[0]);
    dp[1] = max(dp[0] + a[1], b[1]);
    for (int i = 2; i<N; i++) {
        dp[i] = max(dp[i-1] + a[i], dp[i-2] + b[i]);
    }
    return dp[N-1];
}
