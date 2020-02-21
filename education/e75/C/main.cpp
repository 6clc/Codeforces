#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    vector<char> nums[2];
    int cur = 0;
    nums[cur].push_back(s[0]);
    for(int i=1; i<s.size(); i++){
        if((s[i]&1) == (s[i-1]&1)){
            nums[cur].push_back(s[i]);
        }else{
            cur = !cur;
            nums[cur].push_back(s[i]);
        }
    }

    string t = "";
    int i=0;
    int j=0;
    while(i<nums[0].size() && j<nums[1].size()){
        if(nums[0][i] < nums[1][j]) {
            t.push_back(nums[0][i]);
            i++;
        }else{
            t.push_back(nums[1][j]);
            j++;
        }
    }
    while(i<nums[0].size()){t.push_back(nums[0][i]); i++;}
    while(j<nums[1].size()){t.push_back(nums[1][j]); j++;}
    cout << t << endl;

}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
