#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

map<string, int> mps;
vector<pair<int, string>> nums;
string s;

void erro(){
      cout << "error.0001" << endl;
      return;
}

bool isok(char ch){
    if((ch>='a' && ch<='z') || (ch >='A' && ch<='Z')){
        return true;
    }
    return false;
}


bool check(string name){
    if(!((name[0] >= 'A') && (name[0] <= 'Z'))) return false;
    
    for(int i=1; i<name.size(); i++){
        if(! ((name[i] >= 'a') && (name[i] <='z'))) return false;
    }
    return true;

}

bool solve(){
    string cur;
    bool f = false;

    for(int i=0; i<s.size(); i++){
        if(s[i] == ','){
            if(i==0) return false;
            else if(s[i-1] == ',') return false;

            if(!check(cur)) return false;

            mps[cur] += 1;
            cur.clear();
        }else{
            cur.push_back(s[i]);
        }
    }
    return true;
}
int main(){
    cin >> s;
    if(s.back() != ',') s.push_back(',');

    if(!solve()){
        erro();
        return 0;
    }

    for(auto kv:mps){
        nums.push_back({-kv.second, kv.first});
    }

    if(nums.size() == 0){
        erro();
        return 0;
    }


    sort(begin(nums), end(nums));
    cout << nums[0].second << endl;

    return 0;
}