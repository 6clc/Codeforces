#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve(){
    ll n, g, b;
    cin >> n >> g >> b;

    ll lf = n;
    ll rg =  1e18L;
    ll t = g+b;
    ll target = (n+1)/2;

    while(lf < rg){
        ll mid = (rg+lf)/2;
        ll cur_g = ((mid/t) * g) + (mid%t > g ? g : mid%t);
        if(cur_g >= target) rg = mid;
        else lf = mid + 1;
    }
    cout << lf << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}