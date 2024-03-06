#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int idx = 0;
    int n = s.size();
    int p[1000005];
    long long res[3][1000005];
    char c[1000005];
    for (int i = 0; i < n; ++i){
        if (s[i] == s[i + 1] && i + 1 < n){
            p[1 + idx] ++;
        } else {
            c[1 + idx] = s[i];
            p[1 + idx++] ++;
        }
    }

    n = idx;
    res[0][0] = 1LL;
    for (int i = 0; i < n; ++i){
        res[0][i + 1] += res[0][i];
        res[1][i + 1] += res[1][i];
        res[2][i + 1] += res[2][i];
        if (p[i + 1] >= 2){
            res[2][i + 1] += res[0][i];
        } 
        if (p[i + 1] >= 1){
            if (i + 2 <= n && p[i + 1] == 1 && c[i] == c[i + 2]){
                res[2][i + 2] -= 1;
            } 
            res[1][i + 1] += res[0][i];
            res[2][i + 1] += res[1][i];
        }
    }
    cout << res[2][n];
    return 0;
}