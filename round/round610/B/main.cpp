#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

void solve(){
    int n, p, k;
    scanf("%d %d %d", &n, &p, &k);
    vector<int> nums(n+1);
    for(int i=1; i<=n; i++) scanf("%d", &nums[i]);

    int dp[n+1];
    sort(begin(nums)+1, end(nums));
    memset(dp, 0, sizeof(dp));

    int ret = 0;
    for(int i=1; i<=n; i++){
        if(i<k)
        dp[i] = dp[i-1] + nums[i];
        if(i>=k) dp[i] = dp[i-k] + nums[i];
    }
    int i;
    for(i=n; i>0; i--){
        if(dp[i] <= p) {
            break;
        }
    }
    cout << i << endl;


}


int main() {
    int t;
    scanf("%d", &t);
    while(t--)
    solve();
    return 0;
}
