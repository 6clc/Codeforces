// _*_ coding: utf-8 _*_
// 
// @File    :   a.cpp
// @Version :   1.0
// @Author  :   刘超
// @Email   :   chaoliu.lc@qq.com
// @Time    :   2020/04/07 18:44:13
// Description:
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nums[int(2e5)+2];
ll d[int(2e5)+2];


int main(){
    int n;
    scanf("%d", &n);

    ll minn;
    for(int i=0; i<n; i++){
        scanf("%lld", &nums[i]);
        if(i!=0){
            d[i] = nums[i] - nums[i-1];
            if(i == 1) minn = d[i];
            else minn = min(minn, d[i]);
        }
    }

    
    for(ll y=minn; y>=2; y--){
        int i;
        for(i=1; i<n; i++){
            if(d[i]%y){
                break;
            }
        }
        if(i==n){
            printf("%lld\n", y);
            return 0;
        }
    }
    printf("%d\n", -1);

    return 0;
}