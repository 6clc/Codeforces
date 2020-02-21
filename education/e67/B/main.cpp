#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // std::cout << "Hello, World!" << std::endl;
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> mps(26);

    for(int i=0; i<s.size(); i++){
        mps[s[i]-'a'].push_back(i+1);
    }

    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        string tmp;
        cin >> tmp;

        int ret = 0;
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for(int j=0; j<tmp.size(); j++){
            cnt[tmp[j]-'a'] ++ ;
            ret = max(ret, mps[tmp[j]-'a'][cnt[tmp[j]-'a']-1]);
        }
        cout << ret << endl;
    }
    return 0;
}
