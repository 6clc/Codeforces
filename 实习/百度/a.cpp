// _*_ coding: utf-8 _*_
// 
// @File    :   a.cpp
// @Version :   1.0
// @Author  :   刘超
// @Email   :   chaoliu.lc@qq.com
// @Time    :   2020/03/29 19:53:40
// Description:
 首先给出n个数字a1,a2,….an，然后给你m个回合，每回合你可以从中选择一个数取走它，剩下来的每个数字ai都要减去一个值bi。如此重复m个回合，所有你拿走的数字之和就是你所得到的分数。

现在给定你a序列和b序列，请你求出最多可以得到多少分。

5
5
10 20 30 40 50
4 5 6 7 8

100
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100+2;
vector<pair<int, int>> nums;
int n, m;

int vis[maxn];


int dfs(int p, int k, int c){
    if(k == m){
        return 0;
    }

    // if(dp[p][k][c] != -1){
    //     return dp[p][k][c];
    // }

    int ret = 0;
    for(int i=p; i>=0; i--){
        
        int cur = dfs(i-1, k+1, c+nums[i].second) + nums[i].first;
        ret = max(cur, ret);
     
    }
    //cout << ret << " " << c << endl;
    return ret-c;
}


int main(){
    
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        scanf("%d", nums[i].first);
    }

    for(int i=0; i<n; i++){
        scanf("%d", nums[i].second);
    }
    memset(vis, 0, sizeof(vis));

    sort(nums.begin(), nums.begin()+n);

    printf("%d\n", dfs(n-1, 0, 0));
    

    return 0;
}