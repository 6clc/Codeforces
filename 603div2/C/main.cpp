#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    int a[n];
    int b[n];

    // 统计左右差值
    int nowl = 0;
    for(int i=n-1; i>=0 ; i--) {
        scanf("%d", &a[i]);
        if(a[i] == 1) nowl += 1;
        else nowl -= 1;
    }

    int nowr = 0;
    for(int i=0; i<n; i++){
        scanf("%d", &b[i]);
        if(b[i] == 1) nowr += 1;
        else nowr -= 1;
    }

    // 消灭差值
    map<int, int> mps;
    mps[nowr] = 0;
    for(int i=0; i<n; i++){
        if(b[i] == 1){
            nowr -= 1;
        }else{
            nowr += 1;
        }
        if(mps.count(nowr)==0){
            mps[nowr] = i+1;
        }
    }


    int ret = 0x3f3f3f3f;
    // 左边一个也不要
    if(mps.count(-nowl) !=0 ) ret = min(ret, mps[-nowl]);

    for(int i=0; i<n; i++){
        if(a[i] == 1){
            nowl -= 1;
        }else{
            nowl += 1;
        }
        if(mps.count(-nowl) != 0) ret = min(ret, i+1 + mps[-nowl]);
    }
    cout << ret << endl;

}
int main() {
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        solve();
    }
    return 0;
}
