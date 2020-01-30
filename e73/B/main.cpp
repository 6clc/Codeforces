#include <iostream>
#include <bits/stdc++.h>
#define MF(x, y, c) make_pair(make_pair(x, y), c)
using namespace std;
const int MAXN = 105;
int nums[MAXN][MAXN];
int n;

bool isok(int x, int y){
    if(x<0 || x>=n) return false;
    if(y<0 || y>=n) return false;
    return nums[x][y] == -1;
}
void bfs(int x, int y, int c){
    queue<pair<pair<int, int>, int>> q;
    q.push(MF(x, y, c));
    nums[x][y] = c;

    int dx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
    int dy[] = {-2, 2, -2, 2, -1, 1, -1, 1};

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        int x = cur.first.first;
        int y = cur.first.second;
        int c = cur.second;
        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nc = !c;
            if(isok(nx, ny)){
                q.push(MF(nx, ny, nc));
                nums[nx][ny] = nc;
            }
        }
    }


}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    cin >> n;
    memset(nums, -1, sizeof(nums));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(nums[i][j] == -1){
                bfs(i, j, 0);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(nums[i][j] == 0){
                cout << 'W';
            }else{
                cout << 'B';
            }
        }
        cout << endl;
    }
    return 0;
}
