#include<iostream>
#include<cstdio>
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
        ll n, p, k;
        cin >> n >> p >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll ans = 0, pref = 0, sum = 0, cnt = 0;
        for(int i = 0; i < k; i++){
            cnt = i;
            sum = pref;
            if(sum > p) break;
            for(int j = i+k-1; j < n; j += k){
                if(sum + a[j] <= p){
                    cnt += k;
                    sum += a[j];
                }
                else{
                    break;
                }
            }
            pref += a[i];
            ans = max(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0;
}
