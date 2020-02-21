#include <bits/stdc++.h>
using namespace std;

void solve(){
    int h;
    int n;
    cin >> h >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) scanf("%d",  &nums[i]);
    nums.push_back(0);
    int ret = 0;
    for(int i=1; i<n; i++){
        if(nums[i] - 1 == nums[i+1]) {
            i++;
            continue;
        }else{
            ret += 1;
        }
    }
    cout << ret << endl;
}

int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
