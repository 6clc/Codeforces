// _*_ coding: utf-8 _*_
// 
// @File    :   d.cpp
// @Version :   1.0
// @Author  :   刘超
// @Email   :   chaoliu.lc@qq.com
// @Time    :   2020/04/07 19:57:43
// Description:
 
#include <bits/stdc++.h>
using namespace std;

const int maxn = 25;

int n;
int m;
int x, y;
int x2, y2;
int mps[maxn][maxn];
int vis[maxn][maxn];
int ret = -1;

int dx[] = {-1, -1, -1, 0,  0,  1, 1, 1};
int dy[] = {-1, 0, 1,  -1,  1,  -1, 0, 1};

int isok(int cx, int cy){
    if(cx <= 0 || cy <= 0 || cx > n || cy > m) return 0;
    if(vis[cx][cy] == 1) return 0;
    if(mps[cx][cy] == 0 || mps[cx][cy] == 5) return 1;
    return 0;
}


void dfs(int cx, int cy, int ck){
    if(cx == x2 && cy == y2){
        if(ret == -1) ret = ck;
        else{
            ret = min(ret, ck);
        }
        
        return;
    }

    for(int i=0; i<8; i++){
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if(isok(nx, ny)){
            if(mps[cx][cy] == 5 && mps[nx][ny] == 5) continue;

            vis[nx][ny] = 1;
            dfs(nx, ny, ck+ (mps[nx][ny]==5));
            vis[nx][ny] = 0;

        }
    }
}

void test(){
    for(int i=1; i<=n ;i++){
        for(int j=1;j<=m;j++){
            cout << mps[i][j] << " ";
        }
        cout << endl;
    }
}
void solve(){
    scanf("%d %d",&n ,&m);
    scanf("%d %d %d %d",&x, &y, &x2, &y2);

    int k;
    scanf("%d", &k);

    memset(mps, 0, sizeof(mps));
    for(int i=0; i<k; i++){
        int a, b;
        char ch;
        scanf("%d %d %c", &a, &b, &ch);
        // printf("%d %d %c\n",a , b, ch);

        if(ch == 'B'){
            mps[a][b] = -1;
        }else if(ch == 'u'){
            mps[a][b] = 1;
        }else if(ch == 'd'){
            mps[a][b] = 2;
        }else if(ch == 'l'){
            mps[a][b] = 3;
        }else if(ch == 'r'){
            mps[a][b] = 4;
        }
    }
    
    // test();

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(mps[i][j] == 0 || mps[i][j] == -1 || mps[i][j] == 5) continue;

            if(mps[i][j] == 1){

                for(int k=i-1; k>0; k--){
                    if(mps[k][j] == 0 || mps[k][j] == 5) mps[k][j] = 5;
                    else break;      
                }

            }else if(mps[i][j] == 2){

                for(int k=i+1; k<=n; k++){
                    if(mps[k][j] == 0 || mps[k][j] == 5) mps[k][j] = 5;
                    else break;  
                }

            }else if(mps[i][j] == 3){

                for(int k=j-1; k>0; k--){
                    if(mps[i][k] == 0 || mps[i][k] == 5) mps[i][k] = 5;
                    else break; 
                }

            }else if(mps[i][j] == 4){
                for(int k=j+1; k<=m; k++){
                    // cout << "sfas " << k << " " << j << endl;
                    if(mps[i][k] == 0 || mps[i][k] == 5) mps[i][k] = 5;
                    else break; 
                }
            }
        }
    }

    // test();
    memset(vis, 0, sizeof(vis));
    ret = -1;
    vis[x][y] = 1;
    dfs(x, y, 0);
    vis[x][y] = 0;
    printf("%d\n", ret);

    
}


int main(){
    int T;
    scanf("%d", &T);
    while (T--)
    {
        solve();
    }
    

    return 0;
}

/*
2
3 3
1 1 3 3
2
2 1 r
2 3 B
3 2
1 2 3 1
2
2 1 B
2 2 B
*/