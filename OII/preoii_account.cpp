#include <bits/stdc++.h>
using namespace std;

int chiedi(int K);
void rispondi(string S);

void indovina(int N) {
    int atm = N*(N+1)/2;
    vector<string> C = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    vector<string> V(N+1, "*");
    for (int i = N; i>1; i--) {
        int x = chiedi(atm);
        V[N-x+1] = C[i-1];
        atm -= x;
    }
    string ans;
    for (int i = 1; i<N+1; i++) {
        if (V[i] == "*") V[i] = "a";
    }
    for (int i = 1; i<N+1; i++) ans += V[i];
    rispondi(ans);
    return;
}
