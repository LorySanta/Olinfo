#include <bits/stdc++.h>
using namespace std;

//prima di costruire la lista è necessario costruire il nodo
struct node {
    string s; //può esserci una qualunque variabile, qua usiamo le stringhe
    node* next;
};

//costruiamo la lista
struct lista {
    //essa è identificata da due puntatori, al primo e all'ultimo elemento
    node* first;
    node* last;

    lista() {
        first = nullptr;
        last = nullptr;
    }

    lista(string S) {
        node* N = new node; //così crea uno spazio in memoria, a cui N punta, e lo lascia in memoria
        N->s = S;
        N->next = nullptr;
        first = N;
        last = N;
    }

    //si possono unire due liste, l'operazione a + b costruisce la lista ab ACHTUNG non è commutativo
    lista operator+(lista l) { 
        lista L; 
        L.first = first; 
        L.last = l.last;
        last->next = l.first;
        return L;
    }
};

int main() {
    //costruisco le variabili
    int N; cin >> N;
    vector<lista> V(N);
    for (int i = 0; i<N; i++) {
        string s; cin >> s;
        V[i] = lista(s);
    }
    //eseguo le queries
    lista ans;
    for (int i = 0; i<N-1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        V[a] = V[a] + V[b];
        ans = V[a];
    }

    node* ptr = ans.first;
    while (ptr != nullptr) {
        cout << ptr->s;
        ptr = ptr->next;
    }
}
