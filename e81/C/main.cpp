#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
void solve(){
    string s;
    string t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();
    int nxt[n+1][26];

    for(int i=0; i<26; i++){
        nxt[n-1][i] =  INF;
        nxt[n][i] = INF;
    }
    nxt[n-1][s[n-1]-'a'] = n-1;

    for(int i=n-2; i>=0; i--){
        for(int j=0; j<26; j++){
            nxt[i][j] = nxt[i+1][j];
        }
        nxt[i][s[i]-'a'] = i;
    }

    int res = 1;
    for(int i=0, j=0; i<m; i++){
        int cur = t[i] - 'a';
        if(nxt[j][cur]==INF){
            if( j==0 ) {cout << -1 << endl; return;}
            // cout  <<i << "*" << endl;
            j = 0;
            res += 1;
            if(nxt[j][cur] == INF) {cout << -1 << endl; return;}
        }

        j = nxt[j][cur]+1;
    }
    cout << res << endl;
}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
