long long fastpow(long long a, int b, long long N) {
    if (b == 0) return 1;
    long long x = fastpow(a, b/2, N)%N;
    x = (x*x)%N;
    if (b%2 == 1) x = (x*a)%N;
    return x;
}


void decifra(int N, int d, int L, int* messaggio, char* plaintext) {
    for (int i = 0; i<L; i++) {
        plaintext[i] = fastpow(messaggio[i], d, N);
    }
}
