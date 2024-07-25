#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //prendo gli input
    int N, L; cin >> N >> L;
    string S; cin >> S;


    //costrusco le variabili necessarie
    bool impossibile = false;
    vector<char> V(N);
    vector<bool> visto(N);
    vector<char> numeri = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};


    for (int i = 0; i<L/2; i++) {
        int j = L-i-1;
        bool numi = false, numj = false;
        int numero;
        //controllo se sono cifre
        for (int x = 0; x<N; x++) {
            if (S[i] == numeri[x]) {
                numi = true;
                numero = (int)(S[i]) - 48;
            }
        }
        for (int x = 0; x<N; x++) {
            if (S[j] == numeri[x]) {
                numj = true;
                numero = (int)(S[j]) - 48;
            }
        }
        //caso in cui sono numero/numero
        if (numj && numi) continue;
        //caso in cui sono NaN/NaN
        else if ((!numj) && (!numi)) {
            if (S[i] != S[j]) {
                impossibile = true;
                break;}
            else continue;
        }
        //i è un numero
        else if (numi) {
            if (visto[numero] && S[j] != V[numero]) {
                impossibile = true;
                break;
            }
            visto[numero] = true;
            V[numero] = S[j];
        }
        //j è un numero
        else if (numj) {
            if (visto[numero] && S[i] != V[numero]) {
                impossibile = true;
                break;
            }
            visto[numero] = true;
            V[numero] = S[i];
        }
    numi = false; numj = false;
    }


    for (int i = 0; i<N; i++) {
        if (!visto[i]) impossibile = true;
    }
   
    if (impossibile) cout << "impossibile" << endl;
    else {
        string ans = "";
        string sup;
        for (auto i:V) {
            sup = i;
            ans = ans + sup;
        }
        cout << ans << endl;
    }




    return 0;
}
