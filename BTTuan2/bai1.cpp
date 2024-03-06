#include <bits/stdc++.h>
using namespace std;

bool prime(int n){
    for (int i = 2; i <= sqrt(n); ++i){
        if (n % i) return 0;
    }

    return 1;
}

int main(){

    int n; cin >> n;
    cout << (prime(n)  ? "Yes" : "No") << endl;
    return 0;
}