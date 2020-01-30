#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
void solve(){
    ll n, k;
    cin >> n >> k;
    ll ret = 0;
    while(n){
        ret += n%k + 1;
        n = n/k;
    }
    cout << ret-1 << endl;
}

int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
