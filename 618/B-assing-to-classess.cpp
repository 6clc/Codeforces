#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    n = 2*n;

    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    sort(begin(nums), end(nums));
    cout << nums[n/2] - nums[n/2-1] << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}