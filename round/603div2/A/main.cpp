#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;
int main() {
    ll rr, gg, bb;
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%lld %lld %lld", &rr, &gg, &bb);
        ll tot = rr + gg + bb;
        ll l = 0;
        ll r = tot;
        while(l<r){
            ll mid = (l+r) / 2;
            tot = min(mid, rr) + min(mid, gg) + min(mid, bb);

            // cout << mid <<  " " << r<< " " << tot << endl;
            if(mid*2 <= tot) l = mid+1;
            else r = mid;
        }
        tot = min(l, rr) + min(l, gg) + min(l, bb);
        ll ans;
        int cnt = 0;
        for(ll i=l; i>=0; i--){
            tot = min(i, rr) + min(i, gg) + min(i, bb);
            if(i*2 <= tot) {
                ans=i;
                // cout << cnt;
                break;
            }
            cnt += 1;
        }
       cout << ans << endl;
    }
    return 0;
}
