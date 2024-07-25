#include <stdio.h>
#include <assert.h>

int compra(int N, int M, int A, int B) {
    // Mettete qui il codice della soluzione
    int costo = 0;
    if (A*M>B) {
        costo = N/M*B;
        if ((N%M)*A>B) {
            costo += B;
        }
        else {
            costo += (N%M)*A;
        }
    }
    else {
        costo = N*A;
    }
    return costo;
}


int main() {
    FILE *fr, *fw;
    int N, M, A, B;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &A, &B));

    fprintf(fw, "%d\n", compra(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
