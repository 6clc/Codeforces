#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(){
    vector<int> a(3);
    for(int i=0; i<3; i++) cin >> a[i];
    sort(begin(a), end((a)));
    if(a[0] <= a[2] && a[1] <= a[2] && a[0] + a[1] >= a[2]-1) cout<<"YES"<<endl;
    else cout << "NO" << endl;
}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
