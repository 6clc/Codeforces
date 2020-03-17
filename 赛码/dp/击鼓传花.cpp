// _*_ coding: utf-8 _*_
// 
// @File    :   击鼓传花.cpp
// @Version :   1.0
// @Author  :   刘超
// @Email   :   chaoliu.lc@qq.com
// @Time    :   2020/03/11 18:01:38
// Description:
 
#include <bits/stdc++.h>
using namespace std;

int n;
int m;

int main(){
    cin >> n >> m;
    int dp[m+1][n];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for(int i=1; i<=m; i++){
        for(int j=0; j<n; j++){
            dp[i][j] = dp[i-1][(j-1+n)%n] + dp[i-1][(j+1)%n];
            // cout << dp[i][j] << " ";
        }
       // cout << endl;
    } 
    cout << dp[m][0] << endl;
    return 0;
}