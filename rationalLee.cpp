#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> integers(n), friends(k);
        for(int i = 0; i < n; i++){
            cin >> integers[i];
        }
        for(int i = 0; i < k; i++){
            cin >> friends[i];
        }
        sort(integers.begin(), integers.end());
        sort(friends.begin(), friends.end());
        ll ans = 0;
        ll i = n-1, j = n-k-1, p = 0;
        while(p < k){
            ans += integers[i];
            if(friends[p] > 1){
                j -= (friends[p]-1)-1;
                ans += integers[j];
                j--;
            }
            else{
                ans += integers[i];
            }
            i--;
            p++;
        }
        cout << ans << endl;
    }
    return 0;
}
