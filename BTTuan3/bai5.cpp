#include <bits/stdc++.h>
using namespace std;

int const maxn = 100;
int spiral[maxn][maxn];

int main(){
    int n, m; cin >> n >> m;
    
    int col_start = 1, col_end = m, row_start = 1, row_end = n;
    int value = 1;
    while (col_start <= col_end &&  row_start <= row_end) {
        for (int i = col_start; i <= col_end; ++i){
            spiral[row_start][i] = value;
            value++;
        }
        ++row_start;

        for (int i = row_start; i <= row_end; ++i){
            spiral[i][col_end] = value;
            value++;
        }
        col_end--;

        for (int i = col_end; i >= col_start; --i){
            spiral[row_end][i] = value;
            value++;
        }
        row_end--;

        for (int i = row_end; i >= row_start; --i){
            spiral[i][col_start] = value;
            value++;
        }
        col_start++;
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cout << spiral[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}