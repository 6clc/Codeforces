#include <iostream>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);

        unordered_map<string, int> mp;
        vector<int> need(n, 0);
        set<string> visit;
        vector<string> strs;

        int cnt = 0;
        for(int i=0; i<n; i++){
            string str;
            cin >> str;
            strs.push_back(str);
            if(mp.count(str) == 0){mp[str]=1; visit.insert(str);}
            else{ mp[str]+=1; need[i] = 1; cnt+= 1;}
        }

        printf("%d\n", cnt);


        for(int k=0; k<n; k++){
            if(need[k]){
                bool flag = true;
                for(int i=0; i<4 && flag; i++){
                    for(int j=0; j<10 && flag; j++){
                        string tmp = strs[k];
                        tmp[i] = '0' + j;
                        if(visit.count(tmp) == 0){
                            strs[k] = tmp;
                            visit.insert(tmp);
                            flag = false;
                        }
                    }
                }
            }
            cout << strs[k] << endl;
        }

    }
    return 0;
}
