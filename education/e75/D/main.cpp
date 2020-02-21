#include <bits/stdc++.h>
using namespace std;
const int N = int(2e5) + 99;
const int INF = int(1e9) + 100;
typedef long long ll;

int t;
int n;
ll s;
pair<int, int> nums[N];

bool isok(int x){

    vector<int> v;
    ll sum = 0;

    int cnt = 0;
    for(int i=0; i<n; i++){
        if(nums[i].first >= x) {
            sum += nums[i].first;
            cnt += 1;
        }
        else if(nums[i].second < x) {
            sum += nums[i].first;
        }
        else v.push_back(nums[i].first);
    }
   //  if(v.size() + cnt < n/2) return false;
    int ret = v.size() + cnt  - (n+1)/2;
    if (ret < 0) return false;
    for(int i=0; i<v.size(); i++){
        if(i<ret) sum += v[i];
        else sum += x;
    }
   // cout << sum << endl;
    return sum <= s;
}
void solve(){
    cin >> n >> s;
    for(int i=0; i<n; i++){
        scanf("%d %d",&nums[i].first, &nums[i].second);
    }

    sort(nums, nums+n);
    ll lf = 1;
    ll rg = INF;
    while(lf < rg){
        int mid = (lf + rg) / 2;
        if(isok(mid)){
            lf = mid + 1;
        }else{
            rg = mid;
        }
    }
    cout << lf-1 << endl;
}


int main() {
    // std::cout << "Hello, World!" << std::endl;
    cin >> t;
    while(t--) solve();
    return 0;
}
