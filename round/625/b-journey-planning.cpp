// _*_ coding: utf-8 _*_
// 
// @File    :   b-journey-planning.cpp
// @Version :   1.0
// @Author  :   刘超
// @Email   :   chaoliu.lc@qq.com
// @Time    :   2020/03/02 15:52:20
// Description:
 
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<int, long long> mps;
    long long ret = 0;

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        mps[a-i]+=a;
        ret = max(ret, mps[a-i]);
    }
    cout << ret << endl;
    return 0;
}