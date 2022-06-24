#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

const int N = 2e5+5;

int a[N];
int max_power[N];

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        max_power[n+1] = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            max_power[i] = 0;
        }
        int m;
        cin >> m;
        for(int i = 1; i <= m; i++){
            int p, s;
            cin >> p >> s;
            max_power[s] = max(max_power[s], p);
        }
        for(int s = n-1; s >= 1; --s){
            max_power[s] = max(max_power[s], max_power[s+1]);
        }
        int p = 1, ans = 0;
        a[n+1] = 1e9+7;
        while(p <= n){
            ++ans;
            int need_power = 0, next = p;
            for(int i = p; i <= n+1; i++){
                need_power = max(need_power, a[i]);
                if(need_power > max_power[i-p+1]){
                    next = i;
                    break;
                }
            }
            if(next == p){
                ans = -1;
                break;
            }
            p = next;
        }
        cout << ans << "\n";
    }
    return 0;
}
