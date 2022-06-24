#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
void solve(){
    string s;
    cin >> s;
    int l = s.length();
    if(l <= 3){
        cout << "YES\n";
        return;
    }
    int idx1 = l, idx2 = 0;
    for(int i = 3; i < l; i++){
        if(s[i-3] == '1' && s[i-2] == '1' && s[i-1] == '0' && s[i] == '0'){
            cout << "NO\n";
            return;
        }
    }
    for(int i = 1; i < l; i++){
        if(s[i] == '1' && s[i-1] == '1'){
            idx1 = i;
            break;
        }
    }
    for(int i = l-1; i > 0; i--){
        if(s[i] == '0' && s[i-1] == '0'){
            idx2 = i;
            break;
        }
    }
    if(idx1 < idx2){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
