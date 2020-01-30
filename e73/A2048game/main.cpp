#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    bool f=false;
    long long ret = 0;
    for(int i=0; i<n; i++){
        cin >> nums[i];
        if(nums[i] <= 2048)  ret += nums[i];
    }
    if(ret >= 2048) cout <<"YES" << endl;
    else cout << "NO" << endl;
}
int main() {
   //  std::cout << "Hello, World!" << std::endl;
   int t;
   cin >> t;
   while(t--) solve();
    return 0;
}
