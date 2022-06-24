#include<iostream>
using namespace std;
#define int long long
const string t = "abacaba";
const int N = 1e5 + 1;
bool contains(string s){
    int cnt = 0, n = s.size();
    for(int i = 0; i <= n-7; i++){
        if(s.substr(i, 7) == t){
            cnt++;
        }
    }
    return (cnt == 1);
}
void process(string s){
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] == '?'){
            cout << "d";
        }
        else{
            cout << s[i];
        }
    }
    cout << endl;
}
void solve(){
    int i, j, n, m;
    cin >> n; 
    string s;
    cin >> s;
    if(contains(s)){
        cout << "YES" << endl;
        process(s);
        return;
    }
    for(i = 0; i <= n-7; i++){
        string str = s;
        bool flag = true;
        for(j = 0; j < 7; j++){
            if(str[i+j] != '?' && str[i+j] != t[j]){
                flag = false;
                break;
            }
            str[i+j] = t[j];
        }   
        if(flag and contains(str)){
            cout << "YES" << endl;
            process(str);
            return;
        }
    }
    cout << "NO" << endl;
}
int32_t main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
