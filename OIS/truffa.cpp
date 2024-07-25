#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int sfangate(int N, int V[]) {
    sort(V, V + N);
    int cont = 0; int it = 0; int sum = 0;
    for (int i = 0; i<N; i++) sum = sum + V[i];
    while (sum <= 0) {
        sum = sum - 2*V[it];
        cont++;
        it++;
    }
    return cont;
}

int V[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &V[i]));
    fprintf(fw, "%d\n", sfangate(N, V));
    fclose(fr);
    fclose(fw);
    return 0;
}
