#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int nums[n+1];

    for(int i=1; i<=n; i++){
        cin >> nums[i];
    }
    // cout << k << m-1 << endl;
    // return;
    k = min(k, m-1);

    int ret = 0;
    for(int i=0; i<=k; i++){
        int cur = 0x3f3f3f3f;
        // cout << m << k << " " <<'*' << endl;
        for(int j=0; j<=m-1-k; j++){
           //  cout << i << " " << j  << endl;
            int lf = i+j+1;
            int rg = lf + n-m;
            cur = min(cur, max(nums[lf], nums[rg]));
        }
        ret = max(ret, cur);
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
