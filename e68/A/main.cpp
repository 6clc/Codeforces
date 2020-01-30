#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void solve(){
    int x;
    int n;
    cin >> n >> x;

    int cur = 1;
    int th = 0;
//    for(int i=1; i<=n; i ++){
//        th += 1;
//        if(th == cur){
//            th -= 1;
//            cur += 1;
//            cout << i << " -- " << endl;
//        }
//    }
    cout << 2*x << endl;
}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
