#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int x;
string  s;

int valid(int x){
    int cur = 0;
    int ret = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '0') cur += 1;
        else cur -= 1;
        if(cur == x) ret ++;
    }
    for(int i=s.size()-1; i>=0; i--){
        if(s[i] =='0') cur -= 1;
        else cur += 1;
        if(cur == x) ret ++;
    }
    return ret;
}
void solve(){

    cin >> n >> x;
    cin >> s;

    vector<int> nums(n);

    for(int i=0; i<n; i++){
        if(i == 0) {
            if (s[i] == '0') nums[i] = 1;
            else nums[i] = -1;
        }else{
            if (s[i] == '0') nums[i] = nums[i-1] + 1;
            else nums[i] = nums[i-1] - 1;
        }
        // cout << i << " " << nums[i] << endl;
    }

    if(nums[n-1] == 0){
        for(int i=0; i<n; i++){
            if(nums[i] == x) {
                cout << -1 << endl;
                return;
            }
        }
        cout << 0 << endl;
        return;
    }

    int ret = 0;
    if(x==0) ret ++;
    for(int i=0; i<n; i++){
        if((x-nums[i])%nums[n-1] == 0  && ((x>=nums[i] && nums[n-1]>0) || (x<=nums[i]&&nums[n-1]<0))) ret += 1;
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
