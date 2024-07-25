#include <bits/stdc++.h>
using namespace std;
//salvo qui il binary tree (segment) e la larghezza di H
vector<int> st;
int Hsize;


pair<int, int> chiedi(int x) {
    int N = st.size()/2; x = x+N; //reindicizzo x così da esplorare il segment tree
    //spezzo in due parti: bound sinistro e bound destro (a, b);
    //Inizio col sinistro
    int a = x;
   int pw = 1 << (int)log2(a);
    while (st[a] <= st[x]) { //salgo l'albero
        if (a<pw) pw = pw/2;
        if (a==pw) break; //se è una potenza di due x è il maggiore a sinistra
        if (a%2 == 1) a=a/2;
        else if (a%2 == 0 && a != 2) a--;
    }


    while (!(a < 2*N && a>=N)) { //scendo l'albero
        if (st[2*a+1] > st[x]) a = 2*a+1;
        else a = 2*a;
    }
   
    //procedo col destro
    int b = x;
    while (st[b] <= st[x]) { //salgo l'albero
        if (b%2 == 0) b=b/2;
        else if (b%2 == 1 && b != 3) b++;
        if (b == 3) break; // se salisse ancora si romperebbe.
    }
   
    while (!(b < 2*N && b>=N)) { //scendo l'albero
        if (st[2*b] > st[x]) b = 2*b;
        else b = 2*b+1;
    }
   
    b = min(b-N, Hsize-1); // per evitare che prenda un nodo con 1e9+7
    return {a-N, b};
}


void cambia(int x, int h) {
    //banale cambio in un segment tree O(2logn)
    st[st.size()/2 + x] = h;
    for (int i = (st.size()/2 + x)/2; i>0; i/=2) st[i] = max(st[2*i+1], st[2*i]);
    return;
}


void inizializza(int N, vector<int> H) {
    Hsize = N;
    N = 1 << ((int)log2(N)+1);
    //lo rendo una potenza di due, che è più comoda da gestire
    for (int i = Hsize; i<N; i++) H.push_back((int)(1e9+7));


    //creo il segment tree
    st.resize(2*N);
    for (int i = 0; i<N; i++) st[i+N] = H[i];
    for (int i = N-1; i>0; i--) st[i] = max(st[2*i], st[2*i+1]);
    return;
}

