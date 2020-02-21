#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;

    int st = -1;
    int ed = -1;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '1'){
            if(st==-1) st = i;
            ed = i;
        }
    }

    int ret = 0;
    for(int j=st; j<=ed; j++){
        if(s[j] == '0') ret += 1;
    }
    cout << ret << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}