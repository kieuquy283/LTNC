#include <bits/stdc++.h>
using namespace std;

bool palind(int n){
    string s = to_string(n);
    for (int i = 0; i < s.size()/ 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) return false;
    }

    return true;
}

int main(){
    int t; cin >> t;
    while (t--){
        int res = 0;
        int a, b; cin >> a >> b;
        for (int i = a; i <= b; ++i){
            if (palind(i)) ++res;
        }

        cout << res << '\n';
    }
}