#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    while (N != 1) {
        cout << N << endl;
        if (N%2 == 1) N = 3*N +1;
        else N = N/2;
    }
    cout << "1" << endl;
    return 0;
}
