#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main() {
    // std::cout << "Hello, World!" << std::endl;
    int n;
    int m;
    cin >>n >> m;
    vector<string> s1(n);
    vector<string> s2(m);
    for(int i=0; i<n; i++) {
        string tmp;
        cin >> s1[i];
    }
    for(int i=0; i<m; i++) {
        string tmp;
        cin >> s2[i];
        // cout << s2[i] << endl;
    }
    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        t-=1;

       cout << s1[t%n] << s2[t%m] << endl;
    }

    return 0;
}
