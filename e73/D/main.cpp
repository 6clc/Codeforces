#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = int(3e5 + 5);
const ll MAXM = ll(1e18+2);
ll a[MAXN];
ll b[MAXN];
void solve(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        scanf("%lld %lld", &a[i], &b[i]);
    }

    map<ll, ll> cur;
    cur[a[0]] = 0;
    cur[a[0]+1] = b[0];
    cur[a[0]+2] = b[0]*2;

    for(int i=1; i<n; i++){
        map<ll, ll> nxt;

        ll pr[] = {0, b[i], b[i]*2};
        nxt[a[i]] = MAXM;
        nxt[a[i]+1] = MAXM;
        nxt[a[i]+2] = MAXM;
        for(auto kv:cur){
            ll h = kv.first;
            if(h == a[i]){
                nxt[a[i]+1] = min(nxt[a[i]+1], cur[h]+pr[1]);
                nxt[a[i]+2] = min(nxt[a[i]+2], cur[h]+pr[2]);
            }else if(h == a[i]+1){
                nxt[a[i]]  = min(nxt[a[i]], cur[h]);
                nxt[a[i]+2] = min(nxt[a[i]+2], cur[h]+pr[2]);
            }else if(h == a[i]+2){
                nxt[a[i]] = min(nxt[a[i]], cur[h]);
                nxt[a[i]+1] = min(nxt[a[i]+1], cur[h]+pr[1]);
            }else{
                nxt[a[i]] = min(nxt[a[i]],  cur[h]);
                nxt[a[i]+1] = min(nxt[a[i]+1], cur[h]+pr[1]);
                nxt[a[i]+2] = min(nxt[a[i]+2], cur[h]+pr[2]);
            }
        }
        cur = nxt;
//        for(auto kv:cur) cout << kv.first << " " << kv.second<< endl;
//        cout << "---" << endl;
    }
    ll ret = MAXM;
    for(auto kv:cur){ret = min(ret, kv.second);}
    cout << ret << endl;

}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
