// _*_ coding: utf-8 _*_
// 
// @File    :   a.cpp
// @Version :   1.0
// @Author  :   刘超
// @Email   :   chaoliu.lc@qq.com
// @Time    :   2020/03/12 19:04:51
// Description:

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s[2];
ll dp[2][55];
int vis[2][55];

int main(){
    
    scanf("%d", &n);
       
    cin >> s[0];
    cin >> s[1];

    int x = 1;
    for(int i=1; i<n-1; i++){
        if(s[0][i] == 'X' && s[1][i] == 'X') return -1;
        if(s[0][i] == '.' && s[1][i] == '.') x*=2;
    }
    cout << x << endl;
    return 0;
}