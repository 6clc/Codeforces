// _*_ coding: utf-8 _*_
// 
// @File    :   b.cpp
// @Version :   1.0
// @Author  :   刘超
// @Email   :   chaoliu.lc@qq.com
// @Time    :   2020/03/12 19:48:53
// Description:
 
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    int nums[n];
    map<int, int> mps;

    int maxn = 0;
    for(int i=0; i<n; i++) {
        cin >> nums[i];
        mps[nums[i]] ++;
        maxn = max(maxn,  mps[nums[i]]);
        int nxt = nums[i] | x;
        if(nxt != nums[i]){
            mps[nxt] ++;
            maxn = max(maxn, mps[nxt]);
        }
    }
    cout << maxn << endl;
    return 0;
}