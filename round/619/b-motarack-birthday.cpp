#include<bits/stdc++.h>
using namespace std;
const int maxn = int(1e5+1);
const int inf = 0x3f3f3f3f;
int nums[maxn];
int n;
void solve(){
    cin >> n;
    for(int i=0; i<n; i++) {
        scanf("%d", &nums[i]);
    }

    int lf = 0;
    int rg = inf;
    while(lf < rg){
        int mid = (lf + rg)/2;
        int cur = 0;
        int nxt = 0;
        for(int i=0; i<n-1; i++){
           int a = nums[i] == -1 ? mid : nums[i];
           int b = nums[i+1] == -1 ? mid : nums[i+1];
           cur = max(cur, abs(a-b));

           a = nums[i] == -1 ? mid+1 : nums[i];
           b = nums[i+1] == -1 ? mid+1 : nums[i+1];
           nxt = max(nxt, abs(a-b));
        }
        if(nxt-cur >= 0){
            rg = mid;
        }else{
            lf = mid + 1;
        }
    }

    int cur = 0;
    for(int i=0; i<n-1; i++){
        int a = nums[i] == -1 ? lf : nums[i];
        int b = nums[i+1] == -1 ? lf : nums[i+1];
        cur = max(cur, abs(a-b));
    }

    cout << cur << " " << lf << endl;


}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}