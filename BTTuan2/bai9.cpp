#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    long long min_a = LONG_MAX, min_b = LONG_MAX;
    while (n--){
        long long a, b;
        cin >> a >> b;
        min_a = min(min_a, a);
        min_b = min(min_b, b);
    }

    cout << min_a * min_b;
    return 0;
}