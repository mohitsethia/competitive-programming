#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
bool palindrome(string &s){
    int n = s.length();
    for(int i = 0; i <= n/2; i++){
        if(s[i] == s[n-i-1]){
        }
        else{
            return false;
        }
    }
    return true;
}
bool all(string &s){
    int n = s.length();
    for(int i = 0; i <= n/2; i++){
        if(s[i] == s[n-i-1] && s[i] == 'a'){
        }
        else{
            return false;
        }
    }
    return true;
}
void solve(){
    string s;
    cin >> s;
    if(s.length() == 1){
        if(s[0] == 'a'){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            cout << s[0] << "a\n";
        }
        return;
    }
    int n = s.length();
    if(all(s))
        cout << "NO\n";
    else{
        string t = s + 'a';
        if(!palindrome(t)){
            cout << "YES\n";
            cout << t << "\n";
            return;
        }
        t = 'a' + s;
        if(!palindrome(t)){
            cout << "YES\n";
            cout << t << "\n";
            return;
        }
        for(int i = 1; i <= n/2; i++){
            t = s.substr(0, i) + 'a' + s.substr(i);
            if(!palindrome(t)){
                cout << "YES\n";
                cout << t << "\n";
                return;
            }
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
