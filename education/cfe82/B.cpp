#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, g, b;
    cin >> n >> g >> b;

    ll need_g = (n+1)/2;
    if(g >= need_g) {cout << n << endl; return;}

    ll ret = (need_g / g) * (g+b) - b;
    ll add = need_g - (need_g / g) * g;
    if(add) ret += add + b;
    if(ret < n) cout << n << endl;
    else cout << ret << endl;
    // cout << ret << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}