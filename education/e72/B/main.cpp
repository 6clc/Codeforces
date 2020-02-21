#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    ll x;
    cin >> n >> x;

    ll maxa = 0;
    ll maxd = 0;
    for(ll i=0; i<n; i++){
        ll a;
        ll b;
        cin >> a >> b;
        maxa = max(maxa, a);
        maxd = max(maxd, a-b);
    }

    ll ret = 1;
    x -= maxa;
    if(x>0){
        if(maxd <= 0) {cout << "-1"  << endl;}
        else
        cout << ret + (x+maxd-1)/maxd << endl;
    }else{
        cout << ret << endl;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
      solve();
    }
    return 0;
}