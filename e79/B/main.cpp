#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    ll s;
    scanf("%lld %lld", &n, &s);
    ll ret = 0;
    ll max_index  = 0;
    ll maxn = 0;
    ll cur_sum = 0;
    bool f = false;
    for(ll i=0; i<n; i++) {
        ll a;
        scanf("%lld", &a);

        if(f) continue;
        cur_sum += a;

        if(maxn < a){
            max_index = i+1;
            maxn = a;
        }

        if(cur_sum<=s) ret = 0;
        else if(cur_sum-maxn <= s) ret = max_index;
        else f = true;
    }
    cout << ret << endl;
}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
