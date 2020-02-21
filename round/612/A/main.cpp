#include <iostream>
#include <cstdio>
using namespace std;

void solve(){
    int n;
    cin >> n;
    getchar();
    int ret = 0;
    int cnt = 0;
    bool f=false;
    while(n--){
        char ch = getchar();
        // cout<<"*"<<ch<<n<<endl;
        if(ch == 'A'){
            f = true;
            ret = max(ret, cnt);
            cnt = 0;
        }else if(f){
            cnt += 1;
        }
    }
    ret = max(ret, cnt);
    cout << ret << endl;
}
int main() {
    int t;
    cin >> t;
    getchar();
    while(t--) solve();
    return 0;
}
