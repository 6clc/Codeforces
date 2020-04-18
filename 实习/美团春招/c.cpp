// _*_ coding: utf-8 _*_
// 
// @File    :   c.cpp
// @Version :   1.0
// @Author  :   刘超
// @Email   :   chaoliu.lc@qq.com
// @Time    :   2020/03/12 20:05:54
// Description:
 
#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int k;
vector<vector<int>> G;
vector<int> f;

int bfs(int x){
    int visit[n];
    memset(visit,0 ,sizeof(visit));

    int cnt = 0;
    set<int> s;

 
    
    queue<pair<int,int>> q;
    s.insert(f[x]);
    visit[x] = 1;
    q.push({x, 0});
    cnt = 0;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int p = cur.first;
        int cost = cur.second;

        if(s.count(f[p]) ==0){
            s.insert(f[p]);
           // cout << p << " " << s.size() << endl;
            cnt += cost;
            if(s.size() == k){
                return cnt;
            }
        }
        for(auto nxt:G[p]){
            // cout <<p << " "<< nxt << endl;
            if(visit[nxt] == 0){
                visit[nxt] = 1;
                q.push({nxt, cost+1});
            }
        }

    }
    return -1;
}
int main(){
    cin >> n >> m >> k;
    f = vector<int>(n);
    G = vector<vector<int>>(n);
    for(int i=0; i<n; i++){
        cin >> f[i];
    }
    for(int i=0; i<m; i++){
        int a;
        int b;
        cin >> a >> b;
        a --;
        b --;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i=0; i<n; i++){
        cout << bfs(i) << " ";
        // break;
    }
    cout << endl;
    return 0;
}