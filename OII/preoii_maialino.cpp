#include <bits/stdc++.h>

bool chiedi(int X);

int indovina() {
    int ans = 0;
    
    chiedi(0);
    for (int i = 1; i < (1<<30); i *= 2) {
        if (chiedi(i)) ans = ans + i;
    }
     
    return ans;
}
