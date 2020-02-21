#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 100+5;
vector<int> nums;
int dp[maxn][maxn][maxn][3];
int n;

int dfs(int pos, int cnt0, int cnt1, int pre){
    if(pos == n+1) return 0;
    if(dp[pos][cnt0][cnt1][pre]!=-1) return dp[pos][cnt0][cnt1][pre];

    if(nums[pos] == 0){
        int a = maxn, b = maxn;
        if(cnt1 > 0)
        a = dfs(pos+1, cnt0, cnt1-1, 1);
        if(cnt0 > 0)
        b = dfs(pos+1, cnt0-1, cnt1, 0);

        if(pre == 2) dp[pos][cnt0][cnt1][pre] = min(a, b);
        if(pre == 1) dp[pos][cnt0][cnt1][pre] = min(a, b+1);
        if(pre == 0) dp[pos][cnt0][cnt1][pre] = min(a+1, b);
    }else{
        int a = dfs(pos+1, cnt0, cnt1, nums[pos]%2);

        if(pre==2 || nums[pos]%2 == pre) return dp[pos][cnt0][cnt1][pre] = a;
        else return dp[pos][cnt0][cnt1][pre] = a+1;

    }
    return dp[pos][cnt0][cnt1][pre];

}
int main() {

    scanf("%d", &n);

    nums = vector<int>(n+1);
    int cnt0 = 0;
    int cnt1 = 0;
    for(int i=0; i<n; i++) {
        int a;
        scanf("%d", &a);
        nums[i+1] = a;
        if(a){
            if(a%2 == 0) cnt0 += 1;
            else cnt1 += 1;
        }
    }

    cnt0 = n/2 - cnt0;
    cnt1 = n/2 - cnt1;
    if(n%2) cnt1 += 1;
    memset(dp, -1 ,sizeof(dp));
    cout << dfs(1, cnt0, cnt1, 2) << endl;
    return 0;
}
