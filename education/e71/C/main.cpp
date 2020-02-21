#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    map<ll, ll> cur;
    cur[1] = b;
    for(int i=0; i<n; i++){
        map<ll, ll> nxt;
        ll x =  ll(s[i] - '0')+1;

        for(auto kv:cur){
            ll h = kv.first;
            if(h==1){
                if(nxt.count(2)){
                    nxt[2] = min(nxt[2], cur[h] + 2*a + 2*b);
                }else nxt[2] = cur[h] + 2*a + 2*b;

                if(x == 1){
                    if(nxt.count(1)){
                        nxt[1] = min(nxt[1], cur[h] + a + b);
                    } else nxt[1] = cur[h] + a + b;
                }

            }else{
                if(nxt.count(2)){
                    nxt[2] = min(nxt[2], cur[h] + a + 2*b);
                }else nxt[2] = cur[h] + a + 2*b;

                if(x == 1){
                    if(nxt.count(1)){
                        nxt[1] = min(nxt[1], cur[h] + 2*a + b);
                    } else nxt[1] = cur[h] + 2*a + b;
                }
            }
        }
        cur = nxt;
    }

    ll ret = -1;
    for(auto kv:cur) {
        if(ret == -1) { ret = kv.second; continue;}
        ret = min(ret, kv.second);
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
