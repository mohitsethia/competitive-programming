#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
using namespace std;
using ll = long long;
vector<ll> mp[1000001], rev_mp[1000001];
vector<ll> ssc;
stack<ll> st;
ll vis[1000001];
ll a[1000001];
void dfs(ll u){
    vis[u] = 1;
    for(auto v: mp[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    st.push(u);
}
void dfs1(ll u){
    vis[u] = 1;
    for(auto v: rev_mp[u]){
        if(!vis[v]){
            dfs1(v);
        }
    }
    ssc.push_back(u);
}
void solve(){
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++){
        cin >> a[i-1];
        mp[i-1].clear();
        rev_mp[i-1].clear();
        vis[i-1] = 0;
    }
    for(ll i = 1; i <= n; i++){
        ll p = i-1;
        ll q = (i-1+a[i-1]+1)%n;
        mp[p].push_back(q);
        rev_mp[q].push_back(p);
    }
    for(ll i = 1; i <= n; i++){
        if(!vis[i-1]){
            dfs(i-1);
        }
    }
    for(int i = 0; i < n; i++){
        vis[i] = 0;
    }
    ll res = 0;
    while(!st.empty()){
        ssc.clear();
        ll temp = st.top();
        st.pop();
        if(!vis[temp]){
            dfs1(temp);
            if(ssc.size() == 1 && mp[ssc[0]][0] != ssc[0]) continue;
                res += ssc.size();
        }
    }
    cout << res << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
