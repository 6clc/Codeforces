#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a;
    int b;
    int c;
    cin >> a >> b >> c;
    int n = a + b + c;
    int ret = n / 3;
    ret = min(ret, a);
    ret = min(ret, b);
    cout << ret << endl;
}



int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
