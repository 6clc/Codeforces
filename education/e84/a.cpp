// _*_ coding: utf-8 _*_
// 
// @File    :   a.cpp
// @Version :   1.0
// @Author  :   刘超
// @Email   :   chaoliu.lc@qq.com
// @Time    :   2020/03/23 22:33:45
// Description:
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll a;
    ll  b;
    cin >> a >> b;

    ll n = a/b;
    ll m = a%b;

    ll x, y;
    if(n%2){
        x = b - m;
        y = m;
    }else{
        x = m;
        y = b-m;
    }
    if(y%2) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}