#include <bits/stdc++.h>
using namespace std;
map<long long int,int> M;

void aggiungi(long long int id) {
    M[id] += 1;
}

void togli(long long int id) {
    M[id] -= 1;
}

int conta(long long int id) {
    return M[id];
}
