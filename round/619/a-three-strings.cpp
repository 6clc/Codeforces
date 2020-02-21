#include<bits/stdc++.h>

using namespace std;
void solve(){
    string a;
    string b;
    string c;
    cin >> a >> b >> c;

    int n = a.length();
    for(int i=0; i<n; i++){
        if(a[i] != c[i] && b[i] != c[i]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}