#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    // cout << n << s << endl;

    vector<int> ret1(n);

    int i = 0;
    int cur = n;
    int lf = 0;
    int rg = 0;
    while(rg < n-1){
        while(rg < n-1 && s[lf] == s[rg]) rg += 1;
        
        if(s[lf] == '>'){
            while(lf < rg) { ret1[lf]=cur; cur--; lf++;}

        }else{
            for(int j=rg; j>=lf; j-- ){
                ret1[j] = cur; cur--; 
            }
            lf = rg+1;
            rg = rg+1;
        }
         if(rg == n-1) ret1[rg] = cur;
    }

    cur = 1;
    lf = 0;
    rg = 0;
    vector<int> ret2(n);
    while(rg<n-1){
        while(rg<n-1 && s[rg] == s[lf]) rg += 1;

        if(s[lf] == '<'){
            while(lf < rg) {ret2[lf] = cur; cur++; lf++;}
        }else{
            for(int i=rg; i>=lf; i--){
                ret2[i] = cur; cur++;
            }
            lf = rg + 1;
            rg = rg + 1;
        }
        if(rg == n-1) ret2[rg] = cur;
    }


    // vector<int> ret2(n);
    // for(int i=0; i<n; i++){

    // }

    for(auto x:ret1) cout << x << " ";
    cout << endl;
    for(auto x:ret2) cout << x << " ";
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}