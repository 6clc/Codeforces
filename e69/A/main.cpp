#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    sort(begin(nums), end(nums));

    int ret  = 0;
    ret = max(0, nums[n-2]-1);
    ret = min(ret, n-2);
    cout << ret << endl;
}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
