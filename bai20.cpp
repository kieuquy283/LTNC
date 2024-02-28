#include <bits/stdc++.h>
using namespace std;

long long Salary(int n){
    if (n > 200) return (n - 200) * 25000 + 3000000;
    if (n > 150) return (n - 150) * 20000 + 2000000;
    if (n > 100) return (n - 100) * 16000 + 1200000;
    return 1200000;
}

long long Tax(int n){
    long long baohiem = Salary(n) * 0.09;
    long long TN_chiuthue = Salary(n) * 0.91;

    if (TN_chiuthue > 2000000) return 500000 * 0.1 + 500000 * 0.15 + (TN_chiuthue - 2000000) * 0.2;
    if (TN_chiuthue > 1500000) return 500000 * 0.1 + (TN_chiuthue - 1500000) * 0.15;
    if (TN_chiuthue > 1000000) return (TN_chiuthue - 1000000) * 0.1;
}

int main(){

    int n; cin >> n;
    cout << Salary(n);
}