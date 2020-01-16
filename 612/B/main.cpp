#include <iostream>
#include <cstdio>
#include<map>
#include<vector>
using namespace std;

int main() {
    vector<string> nums;
    map<string, int> mps;
    string tmp;
    int n, k;
    scanf("%d %d",&n, &k);
    for(int i=0; i<n; i++){
        cin >> tmp;
        nums.push_back(tmp);
        mps[tmp] += 1;
    }

    int s = 'S' + 'E' + 'T';
    int ret = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            string target = "";
            for(int kk=0; kk<k; kk++){
                if(nums[i][kk] == nums[j][kk]) target+=nums[i][kk];
                else target += s - nums[i][kk] - nums[j][kk];
            }
            ret += mps[target];
        }
    }
    cout << ret/3 << endl;

    return 0;
}
