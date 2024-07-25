#include <bits/stdc++.h>
using namespace std;


int main() {
    //costruisco le variabili
    int N, M;
    cin >> N >> M;
    map<int, int> T;
    for (int i = 0; i<N; i++) {int x; cin >> x; T[x]++;}
    vector<int> P(M);
    for (int i = 0; i<M; i++) cin >> P[i];
   
    //Creo il vettore risposta
    vector<int> Ans(M, -1);
   
    for (int i = 0; i<M; i++) {
        if (T.empty()) continue;
        auto a = T.end(); a--;
        if (P[i] >= (*a).first) {
            Ans[i] = (*a).first;
            (*a).second--;
            if ((*a).second <= 0) T.erase((*a).first);
        }
        else {
            auto it = T.lower_bound(P[i]);
            if ((*it).first > P[i] && it != T.end()) {
                if (it == T.begin()) continue;
                else {
                    it--;
                    Ans[i] = (*it).first;
                    (*it).second--;
                    if ((*it).second == 0) T.erase((*it).first);
                }
            }
            if ((*it).first == P[i]) {
                Ans[i] = (*it).first;
                (*it).second--;
                if ((*it).second == 0) T.erase((*it).first);
            }
        }  
    }




    for (int i:Ans) cout << i << endl;
    return 0;
}
