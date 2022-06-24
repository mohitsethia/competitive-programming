#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define endl '\n'
typedef long long ll;
const int MOD = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll ans = 1;
        n--, k--;
        if(n == k || k == 0){
            cout << "1\n";
            continue;
        }
        if(k == 1){
            cout << n << endl;
            continue;
        }
        if(k > n-k){
            k = n-k;
        }
        for(int i = 0; i < k; i++){
            ans *= (n-i);
            ans /= (i+1);
        }
        cout << ans << endl;
    }
    return 0;
}
