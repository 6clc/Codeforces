#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);

    int sum = 0;
    int cnt_0 = 0;
    for(int i=0; i<n; i++){
        cin >> nums[i];
        if(nums[i] == 0) cnt_0 += 1;
        sum += nums[i];
    }

    if(sum + cnt_0 == 0) cnt_0 += 1;
    printf("%d\n",cnt_0);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}