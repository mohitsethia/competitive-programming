#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>
using namespace std;
using ll = long long;
void solve(){
    ll n;
    string s;
    cin >> n >> s;
    assert(n%2 == 0);
    ll bit = 0;
    if(s[0] == '0' || s[s.length()-1] == '0'){
        cout << "NO\n";
        return;
    }
    for(ll i = 0; i < n; i++){
        bit += (s[i] == '0');
    }
    if(bit%2){
        cout << "NO\n";
        return;
    }
    bit = n-bit;
    ll k = 0;
    string a = "", b = "";
    bool flip = false;
    for(ll i = 0; i < n; i++){
        if(s[i] == '1'){
            a += (2*k < bit ? '(' : ')');
            b += a[a.size()-1];
            k++;
        }
        else{
            a += (flip ? '(' : ')');
            b += (flip ? ')' : '(');
            flip = !flip;
        }
    }
    cout << "YES\n";
    cout << a << "\n" << b << "\n";
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
