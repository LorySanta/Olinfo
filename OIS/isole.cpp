/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>
using namespace std;

// constraints
#define MAXN 1000

// input data
int R, C, i, j;
int M[MAXN][MAXN];

//la dfs vede le isole e le distrugge dopo averne vista una
void dfs(int x, int y) {
    if (M[x][y] == 0) return;
    M[x][y] = 0;
    if (x-1 >= 0) dfs(x-1, y);
    if (y-1 >= 0) dfs(x, y-1);
    if (x+1 < R) dfs(x+1, y);
    if (y+1 < C) dfs(x, y+1);
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &R, &C));
    for(i=0; i<R; i++)
        for (j=0; j<C; j++)
            assert(1 == scanf("%d", &M[i][j]));

    //definisco il vettore visto
    vector<vector<bool>> visto(R, vector<bool> (C, false));

    //prima dfs sul bordo, così da togliere le penisole
    for (int i = 0; i<R; i++) dfs(i, 0);
    for (int i = 0; i<R; i++) dfs(i, C-1);
    for (int c = 0; c<C; c++) dfs(0, c);
    for (int c = 0; c<C; c++) dfs(R-1, c);

    //poi dfs sull'interno:
    int isole = 0;
    for (int i = 1; i<R-1; i++) {
        for (int c = 0; c<C-1; c++) {
            if (M[i][c] == 0) continue;
            isole++;
            dfs(i, c);
        }
    }

    printf("%d\n", isole); // print the result
    return 0;
}
