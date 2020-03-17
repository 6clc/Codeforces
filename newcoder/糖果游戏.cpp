#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
vector<int> nums;
int n;

int dfs(int st, int ed){
    if(dp[st][ed] != -1) return dp[st][ed];
    if(st == ed) return nums[st];

    int x = nums[st] - dfs((st-1+n)%n, ed);
    int y = nums[ed] - dfs(st, (ed+1)%n);
    int cur;

    cur = max(x, y);
    return dp[st][ed] = cur;

}
int main(){
    scanf("%d", &n);
    nums = vector<int>(n);
    for(int i=0; i<n; i++){
        scanf("%d", &nums[i]);
    }
    
  
    dp = vector<vector<int>>(n, vector<int>(n, -1));
    int maxn = 0;
    for(int i=0; i<n; i++){
        int cur = nums[i] - dfs((i-1+n)%n, (i+1)%n);
        maxn = max(cur, maxn);
    }
    cout << maxn << endl;
    return 0;
}