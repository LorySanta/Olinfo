#include <vector>
using namespace std;

int trova_massimo(int N, vector<int> V) {
    // Inserisci il tuo codice qui
    int max = V[0];
    for (int i = 1; i<N; i++) {
        if (max < V[i]) max = V[i];
    }
    return max;
}


