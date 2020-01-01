#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

bool check(int a[], int b[]){
    for(int i=0; i<26; i++)
        if(a[i] != b[i])
            return false;
    return true;
}
void solve(){
    string a;
    string b;
    cin >> a;
    cin >> b;
    if(b.size() < a.size()){
        printf("NO\n");
        return;
    }

    int encoder[26];
    memset(encoder, 0, sizeof(encoder));
    for(auto ch:a){
        encoder[ch-'a'] ++;
    }

    int decoder[26];
    memset(decoder, 0, sizeof(decoder));
    for(int i=0; i<a.size()-1; i++){
        decoder[b[i] - 'a']  ++;
    }

    for(int j=a.size()-1; j<b.size(); j++){
        decoder[b[j] - 'a'] ++;
        if(check(encoder, decoder)){
            printf("YES\n");
            return;
        }
        decoder[b[j-a.size()+1] - 'a'] --;
    }
    printf("NO\n");
}
int main() {
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
