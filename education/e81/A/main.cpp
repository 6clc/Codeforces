#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n ;
    cin >> n;
    if(n&1){
        n-=3;
        cout << "7";
    }
    while(n){
        cout << "1";
        n -= 2;
    }
    cout << endl;

}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
