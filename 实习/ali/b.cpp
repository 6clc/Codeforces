#include <bits/stdc++.h>
using namespace std;

int n;

vector<string> nums;
vector<vector<int>> g;
vector<int> dp;
vector<int> vis;

int ret;

int dfs(int p){
    
    if(dp[p] != -1) return dp[p];

    int cur = 0;
    for(auto nxt:g[p]){
        if(vis[nxt] == 0){
            vis[nxt] = 1;
            cur = max(dfs(nxt), cur);
            vis[nxt] = 0;
        }
        
    }
    return dp[p] = cur + nums[p].size();
}

int main(){
    cin >> n;
    nums = vector<string>(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    
    g = vector<vector<int>>(n);
    dp = vector<int>(n, -1);
    vis = vector<int>(n, 0);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            string a = nums[i];
            string b = nums[j];
            if(a[a.size()-1] <= b[0]){
                g[i].push_back(j);
            }
            if(b[b.size() - 1] <= a[0]){
                g[j].push_back(i);
            }
        }
    }
    
    ret = 1;
    for(int i=0; i<n; i++){
        vis[i] = 1;
        ret = max(ret, dfs(i));
        vis[i] = 0;
    }
    cout << ret << endl;
    return 0;
}