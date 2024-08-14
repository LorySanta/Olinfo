#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n; 
    cin >> n;
    vector<int> V(n+6);
    V[0] = 1; V[1] = 2; V[2] = 4; V[3] = 8; V[4] = 16; V[5] = 32;
    for (int i = 6; i < n; i++) {
        for (int x = 1; x<7; x++) V[i] = (V[i] + V[i-x])%((int)(1e9+7));
    }
    cout << V[n-1] << endl;
    return 0;
}
