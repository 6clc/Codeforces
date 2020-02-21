#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, q;
    cin >> n >> q;

    int visit[3][n+1];
    memset(visit, 0, sizeof(visit)); 
    int cnt = 0;
    for(int i=0; i<q; i++){
        // if(i == 0) cout << "Yes" << endl;
        int a, b;
        cin >> a >> b;
        visit[a][b] = 1 - visit[a][b];

        int cur = 0;
        if(visit[a][b]) cur = 1;
        else cur = -1;

        if(a==1){
            if(b-1>=1 && visit[2][b-1]) cnt += cur;
            if(visit[2][b]) cnt += cur;
            if(b+1<=n && visit[2][b+1]) cnt += cur;
        }else{
             if(b-1>=1 && visit[1][b-1]) cnt += cur;
            if(visit[1][b]) cnt += cur;
            if(b+1<=n && visit[1][b+1]) cnt += cur;
        }

        if(cnt == 0) cout << "Yes" << endl;
        else cout << "No" << endl;

    }
    return 0;
}