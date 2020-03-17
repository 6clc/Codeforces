#include<bits/stdc++.h>
using namespace std;
  
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    set<int> S;
    for(int i=0;i<n;i++){
        scanf("%d", &nums[i]);
        S.insert(nums[i]);
    }
      
     
      
    int lf = 0;
    int rg = 0;
    int r = S.size();
    unordered_map<int, int> mps;
    vector<pair<int, int>> ret(10000);
    int cnt = 0;
    int minn = n;
    while(rg < n){
        while(rg < n && mps.size() < S.size()){
            mps[nums[rg]] += 1;
            rg += 1;
        }
        if(mps.size() < S.size()) break;
         
        while(lf < rg){
            if(mps[nums[lf]] == 1){
                mps.erase(nums[lf]);
                if(rg - lf < minn){
                    minn = rg-lf;
                    cnt = 0;
                    ret[cnt++] = {lf+1, rg};
                }else if(rg - lf == minn){
                    ret[cnt++] = {lf+1, rg};
                }
                lf += 1;
                break;
            }else{
                mps[nums[lf]] -= 1;
            }
            lf += 1;
        }
    }
          
   // cout << minn << " " << ret.size() << endl;
    printf("%d %d\n", minn, cnt);
    for(int i=0; i<cnt; i++){
        printf("[%d,%d] ", ret[i].first, ret[i].second);
    }
    printf("\n");
      
    return 0;
}
