#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int H[26][26];
vector<vector<int>> G(26);
int visit[26];
string ret;

void init(){
    memset(H, 0, sizeof(H));
    for(int i=0; i<26; i++) G[i].clear();
}

void dfs(int x){
    visit[x] = 1;
    ret.push_back('a' +  x);

    for(int i=0; i<G[x].size(); i++){
        int nxt = G[x][i];
        if(visit[nxt]==0){
            dfs(nxt);
        }
    }
}
void solve(){
    init();
    cin >> s;
    n = s.size();
    for(int i=0; i<n-1; i++){
        int a = s[i] - 'a';
        int b = s[i+1] - 'a';

        if(!H[a][b]){
             G[a].push_back(b);
            G[b].push_back(a);
            H[a][b] = 1;
            H[b][a] = 1;
        }
       
    }

    for(int i=0; i<26; i++){
        if(G[i].size() > 2){
            cout << "NO" << endl;
            return;
        }
    }

    memset(visit, 0, sizeof(visit));
    ret = "";
    for(int i=0; i<26; i++){
        if(visit[i] == 0 && G[i].size() < 2){
            dfs(i);
        }
    }
   // cout << ret << endl;
    if(ret.size() == 26){
        cout << "YES" << endl;
        cout << ret << endl;
    }else{
        cout << "NO" << endl;
    }
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}