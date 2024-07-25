#include <stdio.h>
#include <assert.h>

double scosse(int N) {
    double n = N;
    return (n-1)*n/4.;
}

int main() {
    FILE *fr, *fw;
    int N;


    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    fprintf(fw, "%.6f\n", scosse(N));
    fclose(fr);
    fclose(fw);
    return 0;
}


