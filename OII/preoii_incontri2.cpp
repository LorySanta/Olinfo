#include <bits/stdc++.h>

bool visita(int N, int A[]) {
    int a = 0;
    int b = N-1;
    bool starta = false, startb = false;
    while (a<=b && a<N && b >= 0) {
        if (a == b && starta && startb) {
            return true;
            break;
        }
        else if (A[a]>A[b]) {
            A[a] -= A[b];
            A[b] = 0;
            b--;
            starta = false;
            startb = true;
        }
        else if (A[a]<A[b]) {
        A[b] -= A[a];
        A[a] = 0;
        a++;
        starta = true;
        startb = false;
        }
        else if (A[a]==A[b]) {
        a++;
        b--;
        starta = true;
        startb = true;
        }
    }

  return false;
}
