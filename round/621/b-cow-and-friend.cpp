#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> nums(n);
    bool f=false;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        if(nums[i] == x){
            f=true;
        }
    }
    if(f){
        cout << 1 << endl;
        return;
    }

    sort(begin(nums), end(nums));

    cout << max(2, (x+nums[n-1]-1) / nums[n-1]) << endl;
}


int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}