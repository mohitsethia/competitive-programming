#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if(s[0] != s[k-1]){
        cout << s[k-1] << "\n";
        return;
    }
    cout << s[0];
    if(s[k] == s[n-1]){
        for(int i = 0; i < (n-1)/k; i++){
            cout << s[n-1];
        }
    }
    else{
        for(int i = k; i < n; i++){
            cout << s[i];
        }
    }
    cout << "\n";
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
