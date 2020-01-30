#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    int m;
    cin >> n >> m;
    char mps[n][m];

    vector<int> row(n, 0);
    vector<int> col(m, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mps[i][j];
            if(mps[i][j] == '*') { row[i] += 1; col[j] += 1;}
        }
    }

    int ret = m + n;
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           int cur = row[i] + col[j] - (mps[i][j] == '*');
           ret = min(ret, m+n-1 - cur);
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
