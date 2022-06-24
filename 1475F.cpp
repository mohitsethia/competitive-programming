#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
#define vi vector<ll>
bool check(vector<vi> a, vector<vi> &b){
    ll n = a.size();
    for(ll j = 0; j < n; j++){
        if(a[0][j] != b[0][j]){
            for(ll i = 0; i < n; i++){
                a[i][j] ^= 1;
            }
        }
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 1; j < n; j++){
            if((a[i][j]^b[i][j]) != (a[i][0]^b[i][0])){
                return false;
            }
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<vi > a(n, vi(n)), b(n, vi(n));
        string s;
        for(ll i = 0; i < n; i++){
            cin >> s;
            for(ll j = 0; j < n; j++){
                a[i][j] = s[j] == '1';
            }
        }
        for(ll i = 0; i < n; i++){
            cin >> s;
            for(ll j = 0; j < n; j++){
                b[i][j] = s[j] == '1';
            }
        }
        if(check(a, b)){
            cout << "YES\n";
            continue;
        }
        for(ll j = 0; j < n; j++){
            a[0][j] ^= 1;
        }
        if(check(a, b)){
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}
