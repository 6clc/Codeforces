#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MF(t, l, r) make_pair(t, make_pair(l, r))

vector<pair<int, pair<int,int>>> nums;
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int n;
    int m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        nums.emplace_back(MF(a, b, c));
//      cout << nums.back().first << endl;
    }

    vector<int> vis(n+1, -1);
    for(int i=0; i<m; i++){
        if(nums[i].first == 1){
            for(int j=nums[i].second.first+1; j<=nums[i].second.second; j++){
                vis[j] = 1;
            }
        }
    }

    for(int i=0; i<m; i++){
        if(nums[i].first == 0){
            int j;
            bool f=false;
            for(j=nums[i].second.first+1; j<=nums[i].second.second; j++){
                if(vis[j] != 1) {f=true; vis[j] = 0;}
            }
            if(!f) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;

    vector<int> ret(n+1);
    ret[0] = 1;
    for(int i=0; i<=n; i++){
        if(vis[i] == 1) ret[i] = ret[i-1] + 1;
        else if(vis[i] == 0) ret[i] = ret[i-1] - 1;
        else ret[i] = ret[i-1];
    }
    for(int i=1; i<=n; i++){
        if(i==1) cout << ret[i];
        else  cout <<" "<<ret[i];
    }
    cout << endl;


    return 0;
}
