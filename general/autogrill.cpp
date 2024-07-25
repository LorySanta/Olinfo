#include <bits/stdc++.h>
using namespace std;
set<long long int> S;
void inizia() {
    return;
}

void apri(long long p) {
    S.insert(p);
    return;
}

void chiudi(long long p) {
    S.erase(p);
    return;
}

long long chiedi(long long p) {
    if (S.empty()) return -1;
    auto it = S.lower_bound(p);

    if (it == S.end()) {it--; return *it;}
    if (*it == p || it == S.begin()) return *it;
    auto B = *it;
    it--;
    auto A = *it;
    if (abs(A-p) >= abs(B-p)) return B;
    else return A;
}
