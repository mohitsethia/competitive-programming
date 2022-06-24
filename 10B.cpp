#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
using ll = long long;
typedef vector<ll> vi;
ll n, k, x;
vector<vi> mp(1002, vi(1002));
void solve(){
    ll px = (k+1)/2;
    ll py = (k+1)/2;
    ll sum = 0, final_ans = 1e9, row = 0, col = 0, sz = 0;
    for(ll i = 1; i <= k; i++){
        for(ll j = 1; j <= k-x+1; j++){
            sum = 0;
            bool flag = true;
            for(ll t = j; t < j+x; t++){
                if(mp[i][t]){
                    flag = false;
                    break;
                }
                sum += abs(t-py)+abs(i-px);
            }
            if(flag && sum < final_ans){
                row = i, col = j, sz = j+x-1;
                final_ans = sum;
            }
        }
    }
    if(final_ans == 1e9)
        cout << "-1";
    else{
        for(ll i = col; i <= sz; i++){
            mp[row][i] = 1;
        }
        cout << row << " " << col << " " << sz;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    while(n--){
        cin >> x;
        solve();
        cout << "\n";
    }
    return 0;
}
