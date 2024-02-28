#include <bits/stdc++.h>
using namespace std;

const string ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const string teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const string tens[] = {"", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string numberToEnglish(int n){
    if (n == 0) return "zero";
    if (n < 0) {
        return "negative" + numberToEnglish(-n);
    }
    if (n >= 1000000) {
        return numberToEnglish(n / 1000000) + " million " + numberToEnglish(n % 1000000);
    }
    if (n >= 1000) {
        return numberToEnglish(n / 1000) + " thousand " + numberToEnglish(n % 1000);
    }
    if (n >= 100){
        return ones[n / 100] + " hundred " + numberToEnglish(n % 100);
    }
    if (n >= 20){
        return tens[n / 10] + " " + numberToEnglish(n % 10);
    }
    if (n >= 11 &&  n <= 19) {
        return teens[n / 10];
    }
    return ones[n];
}

int main(){

    int n; cin >> n;
    cout << numberToEnglish(n);

}