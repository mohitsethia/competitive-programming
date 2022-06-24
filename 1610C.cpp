#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;

#define int long long

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;



int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        // ordered_set<pair<int, int> > st;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++){
            cin >> b[i] >> a[i];
        }
        int l = 1, r = n;
        int ans = 0;
        auto check = [&](int mid){
            int T = 0;
            for(int i = 0; i < n; i++){
                if(a[i] >= T && b[i] >= mid-T-1) T++;
                if(T >= mid) return true;
            }
            return false;
        };
        while(l <= r){
            int mid = (l+r)/2;
            if(check(mid)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
