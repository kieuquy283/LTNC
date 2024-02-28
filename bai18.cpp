#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 1;
    int countSubj = 1;
    double dTB;
    while (n >= 0){
        cout << "Diem mon hoc " << countSubj << ':' ;
        cin >> n;
        if (n > 10){
            cout << "Nhap lai diem mon hoc" << countSubj << ":";
            cin >> n;
        }
        if (n < 0) break;
        ++countSubj;
        dTB += n;
    }
    cout << "So mon hoc " << countSubj - 1 << '\n';
    cout << "Diem trung binh " << dTB / double(countSubj - 1);

    return 0;
}