#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n+1), next(n+1), pos(n+1, n+1);
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(ll i = n; i >= 0; i--){
        next[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    ll x = 0, y = 0, res = 0;
    for(int z = 1; z <= n; z++){
        if(a[x] == a[z]){
            x = z;
        }
        else if(a[y] == a[z]){
            y = z;
        }
        else if(next[x] > next[y]){
            res++;
            x = z;
        }
        else{
            res++;
            y = z;
        }
    }
    cout << res << endl;
    return 0;
}
