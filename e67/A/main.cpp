#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    int s;
    int t;
    cin >> n >> s >> t;
    int b = s + t - n;
    int a = s - b;
    int c = t - b;

    cout << 1 + max(a, c)   << endl;
}
int main() {
    // std::cout << "Hello, World!" << std::endl;

    int t;
    cin  >> t;
    while(t--) solve();
    return 0;
}