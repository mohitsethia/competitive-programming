#include<iostream>
#include<algorithm>
#include<vector>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define int long long
using namespace std;

#define T pair<int, int>
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, t;
    cin >> n >> t;
    vector<int> a(n+1), pref(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
    ordered_set os;
    os.insert({0, 0});
    int ans = 0, idx = 1;
    for(int i = 1; i <= n; i++){
        ans += os.size() - os.order_of_key({pref[i]-t, 1e9});
        os.insert({pref[i], idx++});
    }
    cout << ans << "\n";
    return 0;
}
