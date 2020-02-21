#include<bits/stdc++.h>
using namespace std;
const int MAXN=int(1e5)+2;
int nums[MAXN];
int n;

int main(){
    cin >> n;
    for(int i=0; i<n; i++) scanf("%d", &nums[i]);
    
    int cnt[31];
    memset(cnt, 0, sizeof(cnt));
    for(int j=0; j<=30; j++){
        for(int i=0; i<n; i++){
            if((nums[i] >> j) & 1) cnt[j] += 1;
        }
    }

    int maxnn = -1;
    int idx = 0;
    for(int i=0; i<n; i++){
        int cur = 0;
        for(int j=0; j<=30; j++){
            if((nums[i] >> j) & 1  && cnt[j] == 1) { cur += 1 << j;}
        }
        if(cur > maxnn) maxnn = cur, idx = i;
    }

    cout << nums[idx];
    for(int i=0; i<n; i++){
        if(i==idx) continue;
        cout << " " << nums[i];
    }
    cout << endl;

    return 0;
}