#include <bits/stdc++.h>
using namespace std;

char c[100][100];
int res[100][100];

int main(){

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> c[i][j];
        }
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (c[i][j] == '.'){
                if (c[i - 1][j] == '*') res[i][j] ++;
                if (c[i + 1][j] == '*') res[i][j] ++;
                if (c[i][j - 1] == '*') res[i][j] ++;
                if (c[i][j + 1] == '*') res[i][j] ++;
                if (c[i - 1][j - 1] == '*') res[i][j] ++;
                if (c[i - 1][j + 1] == '*') res[i][j] ++;
                if (c[i + 1][j - 1] == '*') res[i][j] ++;
                if (c[i + 1][j + 1] == '*') res[i][j] ++;
            }
        }
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (c[i][j] == '.') cout << res[i][j] << ' ';
            else cout << "* ";
        }
        cout << '\n';
    }

    return 0;
}