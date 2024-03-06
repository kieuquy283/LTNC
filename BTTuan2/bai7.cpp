#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    int back;
    while (n > 0){
        if (n != back) {
            cout << n << ' ';
            back = n;
        }

        cin >> n;
    }
}