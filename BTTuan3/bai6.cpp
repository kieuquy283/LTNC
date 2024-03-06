#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int res[100][100];
    int value = 1;
    int i = n / 2 + 1, j = n / 2 + 2;
    res[i][j] = value;
    while (value < n * n){
        
        if (!(value % n)) j += 2;
        else {
            j++; i--;
        }
        value++;
        if (j > n) j %= n;
        if (i == 0) i = n;
        res[i][j] = value;
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j)
            cout << res[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}