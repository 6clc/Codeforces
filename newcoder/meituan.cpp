#include <bits/stdc++.h>
using namespace std;

bool cmp(string& a, string& b){
    int i=0;
    int j=0;
    while(i<a.length() && j<b.length()){
        if(a[i]==b[j]){i++; j++; continue;}
        return a[i] < b[j];
    }
    if(i<a.size()) return true;
    return false;
   // return a<b;
}

void quick_sort(vector<string>& s, int st, int ed){
    if(st >= ed) return;
    
    string t = s[st];
    int lf = st;
    int rg = ed-1;

    while(lf<rg){
        while(lf < rg && cmp(s[rg], t)){rg--;}
        if(lf>=rg) break;

        s[lf] = s[rg];
        lf+=1;
        
        while(lf < rg && cmp(t, s[lf])){lf++;}
        if(lf>=rg) break;

        s[rg] = s[lf];
        rg-=1;
    }
    s[lf] = t;
    quick_sort(s, st, lf);
    quick_sort(s, lf+1, ed);
}
int main(){
    vector<string> s;
    string x;
    cin >> x;
    string tmp;
    x.push_back(',');
    for(int i=0; i<x.size(); i++){
        if(x[i] == ','){
            s.push_back(tmp);
            // cout << tmp << endl;
            tmp = "";
        }else{
            tmp.push_back(x[i]);
        }
    }
    quick_sort(s, 0, s.size());
    
    cout<<s[0];
    for(int i=1; i<s.size(); i++){
        cout<<',' << s[i];
    }
    cout << endl;
    
    
    return 0;
}