#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
void solve(){
    ll n;
    string s, t;
    cin >> n >> s >> t;
    if(s == t){
        cout << "YES\n";
        return;
    }
    ll cnt0 = 0, cnt1 = 0, inverted = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] == '0') cnt0++;
        else cnt1++;
    }
    for(ll i = n-1; i >= 0; i--){
        if(inverted%2 == 0){
            if(s[i] == t[i]){
                if(s[i] == '0') cnt0--;
                else cnt1--;
                continue;
            }
            if(cnt0 != cnt1){
                cout << "NO\n";
                return;
            }
            inverted++;
            if(s[i] == '0') cnt1--;
            else cnt0--;
        }
        else{
            if(s[i] == t[i]){
                if(cnt0 == cnt1){
                    inverted++;
                    if(s[i] == '0') cnt0--;
                    else cnt1--;
                }
                else{
                    cout << "NO\n";
                    return;
                }
            }
            else{
                if(s[i] == '0') cnt1--;
                else cnt0--;
            }
        }
    }
    cout << "YES\n";
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
