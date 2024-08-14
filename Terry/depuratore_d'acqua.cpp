#include <bits/stdc++.h>
using namespace std;
bool fine = false;


struct node {
    vector<int> to;
    bool water = false;
};


int rec(vector<node> &grafo, int atm) {
    if (grafo[atm].water) return 0; // passo base
   
    int risp = 0;
    if (grafo[atm].to.size() == 0) {fine = true;}
    for (auto dir:grafo[atm].to) risp += rec(grafo, dir);


    grafo[atm].water = true;
    risp++;
    return risp;


}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int K, R; cin >> K >> R;
    //salvo i bagnati
    int maxN = 0;
    vector<int> provvisorio(K);
    vector<pair<int, vector<int>>> regole(R);


    for (int i = 0; i<K; i++) {
        cin >> provvisorio[i];
        if (provvisorio[i]>maxN) maxN = provvisorio[i];
    }


    for (int i = 0; i<R; i++) {
        int a, n; cin >> a >> n;
        regole[i].first = a;
        if (a>maxN) maxN = a;
        for (int j = 0; j<n; j++) {
            int x; cin >> x;
            regole[i].second.push_back(x);
            if (x>maxN) maxN = x;
            }  
        }


    vector<node> grafo(maxN+3);


    for (int i = 0; i<K; i++) {  
        grafo[provvisorio[i]].water = true;
    }
    //salvo il grafo
    for (int i = 0; i<R; i++) {
        for (int j = 0; j<regole[i].second.size(); j++) {
            grafo[regole[i].first].to.push_back(regole[i].second[j]);
        }
    }
    //faccio la rec
    int ans = rec(grafo, 1);
    if (fine) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
