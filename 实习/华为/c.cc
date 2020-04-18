#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <set>
using namespace std;

const int maxn = 500;
int n;
vector<int> G[maxn];
vector<int> val(maxn);
vector<int> du(maxn);
set<int> S;
int vis[maxn];
typedef long long ll;
bool f;

void solve(){
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n ;i++){
        cin >> nums[i];
    }

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        cin >> val[a];
        S.insert(a);

        for(int j=0; j<nums[i]; j++){
            int b;
            cin >> b;
            G[a].push_back(b);
            du[b] += 1;
        }

    }
}

int dfs(int cur){
    if(S.find(cur) == S.end()){
        cout << "NA" << endl;
        f=false;
        return 0;
    }
    // cout << cur << endl;

    int ret = 0;
    for(auto nxt:G[cur]){
        if(vis[nxt] == 0){
            vis[nxt] = 1;
            ret = max(ret, dfs(nxt));
            vis[nxt] = 0;
        }else{
            cout << "R" << endl;
            f=false;
            return 0;
        }
        if(!f) return 0;
    }

    return ret += val[cur];
}

int main(){
    solve();
    f = true;

    bool isr = false;
    int ret = 0;
    for(auto s:S){
        if(du[s] == 0){
            memset(vis, 0, sizeof(vis));
            vis[s] = 1;

            ret = max(ret, dfs(s));
            if(!f) return 0;

            vis[s] = 0;

            isr = true;
        }
    }

    if(!isr) cout << "R" << endl;
    else{
        cout << ret << endl;
    }

    return 0;
}