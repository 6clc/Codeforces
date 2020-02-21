#include <bits/stdc++.h>
using namespace std;
typedef  long long ll ;
int main() {
    // std::cout << "Hello, World!" << std::endl;
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll cur = 1;
    ll ret = 0;
    for(int i=1; i<n; i++){
        if(s[i] == s[i-1]){
            cur += 1;
        }else{
            ret += cur;
            cur = 1;
        }
    }
    cur = 1;
    for(int i=n-2; i>=0; i--){
        if(s[i] == s[i+1]){
            cur += 1;
        }else{
            ret += cur - 1;
            cur = 1;
        }
    }
    ret = n*(n-1)/2 - ret;
    cout << ret << endl;
    return 0;
}
