#include <bits/stdc++.h>
using namespace std;

struct goods{
    string name;
    double price;
    double number;
};

double Money(goods g){
    return g.price * g.number;
}

bool check(double tien, vector<goods> Goods, int n){
    double sumMoney = 0;

    for (int i = 0; i < n; ++i){
        sumMoney += Money(Goods[i]);
    }

    return (tien >= sumMoney);
}

bool  cmp(goods a, goods b){
    return (a.name[0] < b.name[0]);
}

bool cmpPrice(goods a, goods b){
    return (a.price < b.price);
}

void Input(int n, vector<goods> Goods){
    cin >> n; 
    for (int i = 0; i < n; ++i){
        goods temp;
        cin >> temp.name >> temp.price >> temp.number;
        Goods.push_back(temp);
    }
    sort(Goods.begin(), Goods.end(), cmp);
}

void solve(vector<goods>& Goods, int& n, vector<goods>& buyGoods, double& tien, vector<goods>& boughtGoods){
    int i = 0, numberBought;
    while (i < n){
        for (goods temp : buyGoods){
            if (temp.name == Goods[i].name){
                boughtGoods.push_back(temp);
                Goods[i].number -= temp.number;
                ++numberBought;
            }
            else {++i;}
        }
    }

    for (goods temp : boughtGoods) tien -=  Money(temp);

    sort(Goods.begin(), Goods.end(), cmpPrice);
    while (tien > 0){
        for (goods temp : Goods){
            if (tien > Money(temp)) {
                boughtGoods.push_back(temp);
                tien -= Money(temp);
                temp.number = 0;
                ++numberBought;
            } else {
                int index = tien / temp.price;
                if (index) {
                    goods ind = temp;
                    ind.number = index;
                    boughtGoods.push_back(ind);
                    tien -= Money(ind);
                    temp.number -= index;
                    ++numberBought;
                } else {
                    tien = -1;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < numberBought - 1; ++i){
        if (boughtGoods[i].name == boughtGoods[i + 1].name) {
            boughtGoods[i].number += boughtGoods[i + 1].number;
            boughtGoods[i + 1].number = 0;
        }
    }

    sort(boughtGoods.begin(), boughtGoods.end(), cmp);
    for (goods temp :  boughtGoods) {
        if (temp.number)
        cout << temp.name << " " << temp.price << ' ' << temp.number << "\n";
    }
}

int main(){
    vector<goods> Goods;
    int n; 
    Input(n, Goods);

    double tien; cin >> tien;

    vector<goods> buyGoods;
    int m;
    Input(m, buyGoods);
    

    vector<goods> boughtGoods;
    solve(Goods, n, buyGoods, tien, boughtGoods);

    return 0;
}