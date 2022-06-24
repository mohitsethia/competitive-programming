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

void solve(){
    ll n;
    cin >> n;
    ll a[2*n];
    ll odd = 0, even = 0;
    for(ll i = 0; i < 2*n; i++){
        cin >> a[i];
        if(a[i]%2){
            odd++;
        }
        else{
            even++;
        }
    }
    if(odd == even){
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
