#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // std::cout << "Hello, World!" << std::endl;
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cur = 0;
    string ret;
    for(int i=0; i<n; i++){
        if(s[i] == '(') cur += 1;
        ret.push_back(char('0') + (cur&1));
        if(s[i] == ')') cur -= 1;
    }
    cout << ret<< endl;
    return 0;
}
