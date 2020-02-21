#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int isvalid[26];
    memset(isvalid, 0 ,sizeof(isvalid));

    for(int i=0; i<s.size(); i++){
       int a = s[i] - 'a';
       int b;

       if(i + 1 == s.size()) b=30;
       else b = s[i+1] - 'a';
       if(a==b){
           if(isvalid[a] != 2){
               isvalid[a] = 1;
           }
           i+=1;
       }else{
           isvalid[a] = 2;
       };
    }


    for(int i=0; i<26; i++){
        if(isvalid[i]==2) cout << char('a'+i);
    }
    cout << endl;
}

int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
