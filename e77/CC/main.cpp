#include <bits/stdc++.h>
typedef  long long ll;
using namespace std;
void solve(){
    ll a;
    ll b;
    ll k;
    scanf("%lld %lld %lld", &a, &b, &k);

    if(a>b) swap(a, b);

    ll g = __gcd(a, b);
    a = a/g;
    b = b/g;
    if(b-1 >= (k-1)*a+1) cout << "REBEL" << endl;
    else cout << "OBEY" << endl;
}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
