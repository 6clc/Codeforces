// _*_ coding: utf-8 _*_
// 
// @File    :   c.cpp
// @Version :   1.0
// @Author  :   刘超
// @Email   :   chaoliu.lc@qq.com
// @Time    :   2020/04/07 19:46:09
// Description:
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5000+5;
int n;
int m;
vector<pair<int, int>> nums(maxn);
int vis[maxn];

int main(){

    cin >> n >> m;
    for(int i=0; i<n; i++){
        scanf("%d", &nums[i].first);
    }

    for(int i=0; i<n; i++){
        scanf("%d", &nums[i].second);
    }

    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    ll ret = 0;

    while(cnt < n){
        for(int i=0; i<n; i++){
            if(vis[i] == 0 && nums[i].first < m){
                vis[i] = 1;
                m += 1;
                cnt += 1;
            }
        }
        if(cnt >= n) break;

        int b = 0x3f3f3f3f;
        int idx = -1;
        for(int i=0; i<n; i++){
            if(vis[i] == 0 && nums[i].second < b){
                idx = i;
                b = nums[i].second;
            }
        }

        vis[idx] = 1;
        m += 1;
        ret += b;
        cnt += 1;
    }

    cout << ret << endl;


    return 0;
}