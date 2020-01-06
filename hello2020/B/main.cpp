#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef  long long ll;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> minns;
    vector<int> maxxs;

    ll ans=0;
    ll ret=0;

    for(int i=0; i<n; i++){
        int m;
        scanf("%d", &m);

        int minn = 0x3f3f3f3f;
        int maxx = -1;
        int f = 0;
        for(int j=0; j<m; j++){
            int a;
            scanf("%d", &a);
            if(a > minn){
                f=1;
            }
            minn = min(minn, a);
            maxx = max(maxx, a);
        }

        if(f==1){
            ans += 1ll*n;
            ret += 1;
        }else{
            minns.push_back(minn);
            maxxs.push_back(maxx);
        }
    }

    sort(begin(minns), end(minns));
    sort(begin(maxxs), end(maxxs));

    for(int i=0, j=0; i<maxxs.size(); i++){
        while(j<minns.size() && minns[j] < maxxs[i]) j++;
        ans += ret + 1ll*j;
    }
    cout << ans << endl;
    return 0;
}
