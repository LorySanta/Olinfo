#include <bits/stdc++.h>
using namespace std;


int main() {
    while (1^0) {
        int N, B; cin >> N >> B;
        if (N==-1 && B==-1) break;


        vector<int> C(N);
        priority_queue<pair<int,int>> Q;
        for (int i=0; i<N; i++) {
            cin >> C[i];
            Q.push({C[i], i});
        }
        //faccio una priority queue e itero tutti i B
        vector<int> num(N,1);
        B = B-N;
        for (int i = 0; i<B; i++) {
            int a = Q.top().first, idx = Q.top().second;
            Q.pop();
            num[idx]++;
            if (!(C[idx]%num[idx])) a = C[idx]/num[idx];
            else a = C[idx]/num[idx] + 1;
            Q.push({a, idx});
        }


        cout << Q.top().first << endl;
    }


    return 0;
}
