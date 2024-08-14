#include <bits/stdc++.h>
using namespace std;

struct fenwick{
    vector<int> ft;

    //costruttore
    fenwick(int N) {
        ft.assign(N + 1, 0);
    }

    //la query ritorna il numero di inversioni
    long long query(int x) {
        x++; //inizializzato a 1;
        long long query = 0;
        while (x>0) {
            query += ft[x];
            x = x - (x&(-x));
        }
        return query;
    }

    //segna il punto x come visto;
    void update(int x) {
        x++;
        while (x<ft.size()) {
            ft[x]++; //l'update 
            x = x + (x&(-x));
        }
    return;
    }
};

long long paletta_sort(int N, int V[]) {
    long long ans;
    //osservo che le azione "scambi paletta" equivalgono a sortare due array separati: uno con indici pari e uno con indici dispari
    //creo i due vettori separati;
    int p = (N+1)/2; int d = N/2;
    vector<int> P(p), D(d);
    for (int i = 0; i<p; i++) P[i] = V[i*2];
    for (int i = 0; i<d; i++) D[i] = V[i*2+1];
    

    //poi calcolo la quantità di mosse necessarie a sortare ogni array. Essa corrisponde al numero di inversioni
    long long invP = 0;                              
    fenwick FTP = fenwick(N);
    for (int i = 0; i<p; i++) {
        invP += FTP.query(p-1) - FTP.query(P[i]);
        FTP.update(P[i]);
    }

    long long invD = 0;
    fenwick FTD = fenwick(N);
    for (int i = 0; i<d; i++) {
        invD += FTD.query(d-1) - FTD.query(D[i]);
        FTD.update(D[i]);
    }
    //infine controllo che l'array finale sia sortato
    bool ordine = true;
    sort(P.begin(), P.end()); sort(D.begin(), D.end());
    for (int i = 0; i<N; i++) {
        if (i%2 == 0) V[i] = P[i/2];
        else V[i] = D[i/2];
    }
    for (int i = 0; i<N-1; i++) {
        if (V[i]>V[i+1]) ordine = false;
    }
    ans = invP + invD;
    if (!ordine) return -1;
    return ans;
}
