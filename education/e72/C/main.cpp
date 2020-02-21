#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void solve(){
    string s;
    cin >> s;

    int pre_zero = 0;
    int ret = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '0'){
            pre_zero += 1;
        }else{
            int cur_val = 1;
            int rg = i;
            for(int j=1; j<=20; j++){
                if(cur_val <= pre_zero+(rg-i+1)) ret += 1;
                if(rg+1 >= s.size()) break;
                cur_val = cur_val*2 + (s[++rg] - '0');
            }
            pre_zero = 0;
        }
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
