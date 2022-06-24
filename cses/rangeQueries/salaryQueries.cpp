#include<iostream>
#include<algorithm>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
typedef long long ll;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

Tree<pair<ll, ll> > st;
const ll MOD = 1000000007;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n+1);
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        st.insert({a[i], i});
    }
    for(ll i = 0; i < q; i++){
        char c;
        cin >> c;
        if(c == '!'){
            ll x, y;
            cin >> x >> y;
            st.erase({a[x], x});
            a[x] = y;
            st.insert({a[x], x});
        }
        else{
            ll l, r;
            cin >> l >> r;
            cout << st.order_of_key({r, MOD}) - st.order_of_key({l-1, MOD}) << endl;
        }
    }
    return 0;
}

