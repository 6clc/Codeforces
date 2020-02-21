#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll x;
    ll y;
    cin >> x >> y;
    ll n = x - y;
    if(n!=1) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main() {
    //  std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
