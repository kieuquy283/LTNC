#include <bits/stdc++.h>
using namespace std;

bool palind(string s){
    for (int i = 0; i < s.size()/ 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) return false;
    }

    return true;
}

int main(){
    string s;
    cin >> s;
    cout << (palind(s) ? "Yes" : "No");

    return 0;
    
}