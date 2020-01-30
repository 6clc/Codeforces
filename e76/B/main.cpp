#include <bits/stdc++.h>
using namespace std;
bool dfs(int a, int b){
    if(a==b) return true;
    if(a==3){
        if(b==2) return true;
        else return false;
    }
    if(a==1){
        if(b==1) return true;
        else return false;
    }

    if(a&1) return dfs(a-1, b);
    else return dfs(a-1, b) || dfs(a/2 * 3, b) ;
}
void solve(){
    int a;
    int b;
    cin >> a >> b;
    if(a>3) cout << "YES" << endl;
    else if(a==3 || a==2){
        if(b<=3)  cout << "YES" << endl;
        else cout << "NO" << endl;
    }else if(a==b){
        cout << "YES" << endl;
    }else{
        cout << "NO"  << endl;
    }
}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
