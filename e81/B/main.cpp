#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int x;
string  s;

int valid(int x){
    int cur = 0;
    int ret = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '0') cur += 1;
        else cur -= 1;
        if(cur == x) ret ++;
    }
    for(int i=s.size()-1; i>=0; i--){
        if(s[i] =='0') cur -= 1;
        else cur += 1;
        if(cur == x) ret ++;
    }
    return ret;
}
void solve(){

    cin >> n >> x;

    cin >> s;

    if(x<0){ x = -x;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '0') s[i] ='1';
        else s[i] = '0';
    }}

    int base = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '0') base += 1;
        else base -= 1;
        if(base == x) {cout << -1 << endl; return;}
    }

    int ret = 0;
    int t ;
    if(base <= 0) {
        t=0;
    }else{
        t=x/base;
    }
    int val = base*t;
    ret += valid(x-val);

    cout << ret << endl;

}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
