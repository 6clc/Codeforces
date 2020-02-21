#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int nums[55][55];
vector<pair<int, int>> ret;

bool isok(int x, int y){
    if(nums[x-1][y-1] == 1 && nums[x-1][y] == 1 && nums[x][y-1] == 1) {
        ret.push_back(make_pair(x-1, y-1));
        return true;
    }
    if(nums[x-1][y] == 1 && nums[x-1][y+1] == 1 && nums[x][y+1] == 1){
        ret.push_back(make_pair(x-1, y));
        return true;
    }
    if(nums[x][y-1] == 1 && nums[x+1][y-1] == 1 && nums[x+1][y] == 1){
        ret.push_back(make_pair(x, y-1));
        return true;
    }
    if(nums[x][y+1] == 1 && nums[x+1][y] == 1 && nums[x+1][y+1] == 1){
        ret.push_back(make_pair(x, y));
        return true;
    }
    return false;
}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    cin >> n >> m;
    memset(nums, 0, sizeof(nums));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> nums[i+1][j+1];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(nums[i][j] == 1){
                if(!isok(i, j)){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << ret.size() << endl;
    for(auto kv:ret) cout << kv.first << " " << kv.second << endl;

    return 0;
}
