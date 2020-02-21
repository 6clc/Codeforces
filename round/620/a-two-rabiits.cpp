#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if(x>y) {cout << -1 << endl; return;}
    y -= x;
    x = 0;
    
    if(y%(a+b) == 0){
        cout << y / (a + b) << endl;
    }else{
        cout << -1 << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}