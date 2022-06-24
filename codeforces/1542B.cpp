#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<set>
#include<numeric>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<climits>

using namespace std;
using ll = long long;

#define pi pair<ll, ll>
#define vi vector<ll, ll>
#define pb push_back
#define eb emplace_back
#define vpi vector<pi>
#define mk make_pair
#define mi map<ll, ll>

ll n;

bool can(ll i, ll a, ll b){
    if(i == n){
        return true;
    }
    if(i > n){
        return false;
    }
    return can(i*a, a, b) || can(i+b, a, b);
}

bool check(ll a, ll b){
    ll x = 1;
    while(n >= x){
        if(x%b == n%b){
            return true;
        }
        x *= a;
    }
    if(n == 1) return true;
    return false;
}

void solve(){
    ll a, b;
    cin >> n >> a >> b;
    if(a == 1){
        if((n-1)%b == 0){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        return;
    }
    if(b == 1){
        cout << "YES\n";
        return;
    }

    if(check(a, b)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 0;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
