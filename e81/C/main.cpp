#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    string t;
    cin >> s >> t;

    vector<vector<int>> mps(26);
    for(int i=0; i<s.size(); i++){
        mps[s[i]-'a'].push_back(i);
    }

    int j=0;
    int ret = 1;
    int cur_ix = -1;

    for(;j<t.size();j++){
        if(mps[t[j]-'a'].size() == 0) {
            cout << -1 << endl;
            return;
        }
        int x = t[j] - 'a';
        bool f=false;
        for(int i=0; i<mps[x].size(); i++){
            if(mps[x][i] > cur_ix){
                cur_ix = mps[x][i];
                f=true;
                break;
            }
        }
        if(f) continue;
        ret += 1;
        cur_ix = mps[x][0];
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
