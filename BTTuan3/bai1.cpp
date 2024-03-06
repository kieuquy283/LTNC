#include <bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    map<int, int> seen;
    bool check = false;
    for (int i = 0; i < n; ++i){
        int a; cin >> a;
        if (seen[a]) check = 1;
        else seen[a] = 1;
    }

    cout << ((check) ? "Yes" : "No");
}