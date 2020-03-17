#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int n = s.size();

    ll ret = 1;
    ll dp[30][30];
    ll cnt[30];
    memset(dp, 0, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<n; i++){
        for(int j=0; j<26; j++){
            dp[j][s[i] - 'a'] += cnt[j];
            ret = max(ret, dp[j][s[i] - 'a']);
        }
        cnt[s[i] - 'a'] += 1;
        ret = max(ret, cnt[s[i] - 'a']);
    }
    cout << ret << endl;
    return 0;
}