#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

int cnt1[200000+5];
int cnt2[200000+5];
int n;
bool check(int d, int target){
    for(int i=n-d+1; i<=n; i++){
        int a = cnt1[i+d-1] - cnt1[i-1];
        int b = cnt2[i+d-1] - cnt2[i-1];
        if(b-a == target) {
            // cout << i-1<< " " <<i-1+d << " " << a << b<< endl;
            return true;
        }
    }
    return false;
}
void solve(){
    scanf("%d", &n);
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    for(int i=1; i<=2*n; i++){
        int tmp;
        scanf("%d", &tmp);
        if(tmp == 1){
            cnt1[i] = cnt1[i-1] + 1;
            cnt2[i] = cnt2[i-1];
        }else{
            cnt1[i] = cnt1[i-1];
            cnt2[i] = cnt2[i-1] + 1;
        }
    }
    if(cnt1[2*n] == cnt2[2*n]){
        printf("0\n");
        return;
    }

    if(cnt1[2*n] > cnt2[2*n]) swap(cnt1, cnt2);
    int target = cnt2[2*n] - cnt1[2*n];
   // cout << target << '*'  << endl;
    int l=1;
    int r=2*n+1;
    for(int mid=l; mid<r; mid++){
        if(check(mid, target)){
            printf("%d\n", mid);
            return;
        }
    }
    while(l<r){
        int mid = (l+r) / 2;
        if(check(mid, target)){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    printf("%d\n", l);

}

int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
