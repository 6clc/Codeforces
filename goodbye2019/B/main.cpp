#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    vector<int> nums(n);

    for(int i=0; i<n; i++) {
        scanf("%d", &nums[i]);
    }

    for(int i=1; i<n; i++){
       if(abs(nums[i] - nums[i-1]) <= 1) continue;
       cout << "yes" << endl;
       printf("%d %d\n", i, i+1);
       return;
    }
    printf("NO\n");
}


int main() {
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
