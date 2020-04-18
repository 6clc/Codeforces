// _*_ coding: utf-8 _*_
// 
// @File    :   a.cpp
// @Version :   1.0
// @Author  :   刘超
// @Email   :   chaoliu.lc@qq.com
// @Time    :   2020/03/20 08:56:19
// Description:
 
#include <bits/stdc++.h>
using namespace std;
vector<int> nums(10);

int ret = 0;

int dfs(int p){
    if(p>=10) return 0;
    if(nums[p] == 0) return dfs(p+1); // A牌没了，打2

    // 出单
    int a = 0x3f3f3f3f;
    int cnt = 0;
    int tmp = nums[p];
  
    nums[p]-= 1;
    a = max(a, 1+dfs(p)); 
    nums[p]+=1;


    // 出5张
    int b = 0x3f3f3f3f;
    bool f = true;
    for(int i=0; i<5; i++){
        nums[p+i] --;
        if(nums[p+i] < 0) f=false;
    }
    if(f) b = dfs(p) + 1;
    for(int i=0; i<5; i++){
            nums[p+i] ++;
    }
   
   // 连对
    int c =  0x3f3f3f3f;
    f = true;
    for(int i=0; i<3; i++){
        nums[p+i] -= 2;
        if(nums[p+i] < 0) f=false;
    }
    if(f) c = dfs(p) + 1;
    for(int i=0; i<3; i++){
        nums[p+i] += 2;
    }
    
    return min(a, min(b,c));
   
}
int main(){
    for(int i=0; i<10; i++){
        cin >> nums[i];
    }
    ret = 0x3f3f3f3f;
    ret = min(ret, dfs(0));
    cout << ret << endl;
    return 0;
}