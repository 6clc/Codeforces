#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void NO(){
    cout << "NO" << endl;
}
void YES(){
    cout << "YES" << endl;
}
void solve(){
    string s, t, p;
    cin >> s >> t >> p;

    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for(auto ch:p) cnt[ch-'a'] += 1;

    int si = 0;
    int ti = 0;
    while(si < s.size()){
        if(ti >= t.size()) {
            NO();
            return;
        }
        if(s[si] == t[ti]){
            si += 1;
            ti += 1;
            continue;
        }
        cnt[t[ti]-'a'] -= 1;
        if(cnt[t[ti]-'a'] < 0){
            NO();
            return;
        }
        ti ++;
    }

    while(ti < t.size()){
        cnt[t[ti]-'a'] -= 1;
        if(cnt[t[ti]-'a'] < 0){
            NO();
            return;
        }
        ti ++;
    }
    YES();

}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
