#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    // std::cout << "Hello, World!" << std::endl;
    ll n;
    ll m;
    ll k;
    cin >> n >> m >> k;
    // cout << n << endl;
    vector<ll> nums(n);
    vector<ll> presum(n);
    for(ll i=0; i<n; i++) cin >> nums[i];

    map<ll, ll> cur;
    ll ret = 0;
    for(ll i=0; i<n; i++){
        map<ll, ll> nxt;

        if(nums[i] - k*ll(ceil(1./m)) > 0){
            nxt[1] = nums[i];
            ret = max(ret, nxt[1] - k*ll(ceil(1./m)));
        }

        for(auto kv : cur){
            ll h = kv.first;
            if(nums[i] + cur[h] - k*ll(ceil(double(h+1)/m)) > 0){
                nxt[h+1] = nums[i] + cur[h];
                ret = max(ret, nxt[h+1] - k*ll(ceil(double(h+1)/m)));
            }
        }
        cur = nxt;
    }
    cout << ret << endl;

    return 0;
}
