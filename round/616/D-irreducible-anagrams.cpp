#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    int Q;

    cin >> s;
    cin >> Q;

    int n = s.size();
    int mps[n+5][27];

    memset(mps, 0, sizeof(mps));
    for(int i=1; i<=n; i++){
        for(int j=0; j<26; j++) {
            mps[i][j] = mps[i-1][j];
        }
        int cur = s[i-1] - 'a';
        mps[i][cur] = mps[i-1][cur] + 1;
    }

    while(Q--){
        int lf;
        int rg;
        cin >> lf >> rg;

        int cnt = 0;
        // lf -= 1;
        // rg -= 1;
        for(int i=0; i<26; i++) {
            if(mps[lf][i] != mps[rg][i]) cnt += 1;
        }
        // cout << cnt << endl;

        if(cnt > 2 || s[lf-1]!=s[rg-1] || lf==rg) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}