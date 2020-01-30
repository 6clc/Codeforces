// #include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i=0; i<n; i++) cin >> nums[i];

    int ret = n+1;
    map<int, int> mps;
    for(int i=0; i<n; i++){
        if(mps.count(nums[i])) ret = min(ret, i-mps[nums[i]]+1);
        mps[nums[i]] = i;
    }

    if(ret == n+1) cout << -1 << endl;
    else cout << ret << endl;
}
int main() {
    //  std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
