#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
        if(i > 1){
            a[i] += a[i-2];
        }
    }
    if(a[n-1] == a[n-2]){
        bool ok = 1;
        for(ll i = 1; i < n; i++){
            if(a[i] < a[i-1]){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        return;
    }
    ll diff = abs(a[n-1]-a[n-2]);
    if(diff%2){
        cout << "NO\n";
        return;
    }
    diff = a[n-1]-a[n-2];
    diff /= 2;
    ll increasing_till = 0;
    for(ll i = 1; i < n; i++){
        if(a[i] >= a[i-1]) increasing_till = i;
        else break;
    }
    for(ll i = 0; i < n; i++){
        c[i] = a[i];
        if(i%2 == (n-1)%2){
            c[i] -= diff;
        }
        else{
            c[i] += diff;
        }
    }
    ll increasing_from = n-1;
    for(ll i = n-2; i >= 0; i--){
        if(c[i] <= c[i+1]) increasing_from = i;
        else break;
    }
    for(ll i = 0; i < n-1; i++){
        if(i%2 == (n-1)%2){
            if(b[i]-b[i+1] == diff){
                if((i == 0 || a[i-1] <= c[i]) && increasing_till >= i-1 && increasing_from <= i){
                    cout << "YES\n";
                    return;
                }
            }
        }
        else{
            if(b[i+1]-b[i] == diff){
                if((i == 0 || a[i-1] <= c[i]) && increasing_till >= i-1 && increasing_from <= i){
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}























/*
#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
bool check(vector<int> a){
    for(int i = 0; i+1 < a.size(); i++){
        if(a[i] > a[i+1]){
            return false;
        }
        a[i+1] -= a[i];
        a[i] = 0;
    }
    if(a.back() == 0){
        return true;
    }
    return false;
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n == 2){
        if(a[0] == a[1]){
            cout << "YES" << endl;
            return;
        }   
        else{
            cout << "NO" << endl;
            return;
        }
    }
    if(check(a)){
        cout << "YES" << endl;
        return;
    }
    if(n == 1){
        cout << "NO" << endl;
        return;
    }
    swap(a[0], a[1]);
    if(check(a)){
        cout << "YES" << endl;
        return;
    }
    swap(a[0], a[1]);
    swap(a[n-1], a[n-2]);
    if(check(a)){
        cout << "YES" << endl;
        return;
    }
    swap(a[n-1], a[n-2]);
    vector<int> p(n), s(n);
    vector<int> b = a;
    p[0] = a[0];
    for(int i = 1; i < n; i++){
        if(p[i-1] == -1 || b[i-1] > b[i]){
            p[i] = -1;
        }
        else{
            b[i] -= b[i-1];
            b[i-1] = 0;
            p[i] = b[i];
        }
    }
    b = a;
    s[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--){
        if(s[i+1] == -1 || b[i] < b[i+1]){
            s[i] = -1;
        }
        else{
            b[i] -= b[i+1];
            b[i+1] = 0;
            s[i] = b[i];
        }
    }
    for(int i = 1; i < n-2; i++){
        vector<int> c = {p[i-1], a[i], a[i+1], s[i+2]};
        if(p[i-1] == -1 || s[i+2] == -1){
            continue;
        }
        swap(c[1], c[2]);
        if(check(c)){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
*/
