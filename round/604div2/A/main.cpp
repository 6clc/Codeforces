#include <iostream>
#include <cstdio>
using namespace std;

string ret;
bool f;

bool check(string& str, int pos){
    if(pos == 0) return str[pos] != str[pos+1];
    else if(pos == str.size() -1) return str[pos] != str[pos-1];
    return str[pos] != str[pos-1] && str[pos] != str[pos+1];

}
void dfs(string &str, int pos){
    if(pos >= str.size()){
        f = true;
        ret = str;
        return;
    }

    while(pos < str.size() && str[pos] != '?'){
        if(!check(str, pos)) return;
        pos++;
    }
    if(pos == str.size()){
        f = true;
        ret = str;
        return;
    }

    for(int i=0; i<3; i++){
        str[pos] = 'a' + i;
        if(check(str, pos)){
           // cout << str << endl;
            dfs(str, pos + 1);
            if(f) return;
        }
    }
}
void solve(){
    string str;
    cin >> str;
    f = false;
    dfs(str, 0);
    if(f) cout<<ret;
    else cout<<-1;
    cout << endl;
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
