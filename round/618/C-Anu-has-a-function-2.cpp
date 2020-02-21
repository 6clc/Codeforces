#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
vector<int> pre_fix;
vector<int> suf_fix;
int n;

int main(){
    cin >> n;
    nums = vector<int>(n);
    pre_fix = vector<int>(n);
    suf_fix = vector<int>(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    pre_fix[0] = INT_MAX;
    suf_fix[n-1] = INT_MAX;

    for(int i=1; i<n; i++) {
        pre_fix[i] = pre_fix[i-1]&(~nums[i-1]);
    }
    for(int i=n-2; i>=0; i--){
        suf_fix[i] = suf_fix[i+1]&(~nums[i+1]);
    }

    int ret = INT_MIN;
    int ret_pos = 0;
    for(int i=0; i<n; i++){
        int cur = pre_fix[i]&suf_fix[i]&nums[i];
        if(cur > ret) ret=cur, ret_pos=i;
    }

    cout << nums[ret_pos] ;
    for(int i=0; i<n; i++){
        if(i==ret_pos) continue;
        else cout << " " << nums[i];
    }
    cout << endl;
    return 0;
}