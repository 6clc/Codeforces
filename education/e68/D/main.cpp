#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    int k;
    cin >> n >> k;

    for(int i=1; i<=k; i++){
        if(iswin(i)){
            cout << "Alice" << endl;
            return ;
        }
    }
    cout << "Bob" << endl;
}

int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
