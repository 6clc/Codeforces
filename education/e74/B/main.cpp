#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    int r;
    cin >> n >> r;
    vector<int> a(n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
//    set<int> S(begin(a), end(a));
//    vector<int> nums(begin(S), end(S));
    sort(begin(a), end(a));

    int cnt = 0;
    n = unique(begin(a), end(a)) - begin(a);
    int lf = 0;
    int rg = n-1;
    int ret = 0;

    for(int i=n-1; i>=0; i--){
        ret += (a[i] - r*ret > 0);
    }
    cout << ret << endl;
}

int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
