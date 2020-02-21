#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a;
    int b;
    int c;
    cin >> a >> b >> c;
    int n = max(0, (c+b-a+2)/2);
    cout << max(c-n+1, 0)<< endl;
}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
