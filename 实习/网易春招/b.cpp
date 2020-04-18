// _*_ coding: utf-8 _*_
// 
// @File    :   b.cpp
// @Version :   1.0
// @Author  :   刘超
// @Email   :   chaoliu.lc@qq.com
// @Time    :   2020/04/07 18:44:09
// Description:
 
#include <bits/stdc++.h>
using namespace std;
const int maxn = 12;

int n;
int k;
int mps[maxn][maxn];
int vis[maxn];

void dfs(int cur, vector<int>& ret){
    if(ret.size() == n){
        printf("%d", ret[0]);
        for(int i=1; i<ret.size(); i++){
            printf(" %d", ret[i]);
        }
        printf("\n");
        return;
    }

    for(int i=1; i<=n; i++){
        if(vis[i] == 1) continue;
        if(mps[i][cur] == 1) continue;

        vis[i] = 1;
        ret.push_back(i);
        dfs(i, ret);
        ret.pop_back();
        vis[i] = 0;
    }
}

int main(){
    memset(mps, 0, sizeof(mps));

    scanf("%d %d", &n, &k);
    for(int i=0; i<k; i++){
        int a;
        int b;
        scanf("%d %d", &a, &b);

        mps[a][b] = mps[b][a] = 1;
    }

    memset(vis, 0, sizeof(vis));

    for(int i=1; i<=n; i++){
        vector<int> ret;
        ret.push_back(i);
        vis[i] = 1;
        dfs(i, ret);
        vis[i] = 0;
    }

    return 0;
}