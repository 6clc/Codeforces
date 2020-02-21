#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> S;
    vector<int> vis(n, 0);
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        S.push_back(s);
    }

    int cnt=0;
    string ret;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){

            bool f=true;
            for(int k=0; k<m; k++){
                if(S[i][k] != S[j][m-1-k]){
                    f=false;
                    break;
                }
            }

            if(f){
               //  cout << i << " " <<j << endl;
                vis[i] = 1;
                vis[j] = 1;
                ret  += S[i];
                break;
            }
        }
    }
    int idx = -1;
    for(int i=0; i<n; i++){
        if(vis[i] == 0){
            bool f = true;
            for(int lf=0, rg=m-1; lf < rg; lf++, rg--){
                if(S[i][lf] != S[i][rg]){f=false; break;}
            }
            if(f){
                idx = i;
                break;
            }
        }
    }
    string tmp;
    for(auto it=rbegin(ret); it<rend(ret); it++) tmp.push_back(*it);

    if(idx!=-1){
        ret = ret + S[idx] + tmp;
    }else{
        ret = ret + tmp;
    }
    cout << ret.size() << endl << ret << endl;
   
    return 0;
}