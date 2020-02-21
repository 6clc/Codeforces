#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
    ll n, m;
    cin >> n >> m;
    ll ret = 1L*n*(n+1)/2;

    n -= m;
    m += 1;

    ll a = n/m;
    ll b = n%m;

    ret = ret - a*(a+1)/2*(m-b) - b*(a+1)*(a+2)/2;
    cout << ret << endl;   

}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}