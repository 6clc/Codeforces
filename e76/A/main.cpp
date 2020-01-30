#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, x, a, b;
    cin >> n >> x >> a >> b;
    int target = max(a, b) - min(a, b) + x;
    target = min(target, n-1);
    cout << target << endl;
}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
