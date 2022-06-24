#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<numeric>
#include<queue>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b){
	return (b == 0 ? a : gcd(b, a%b));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        set<ll> s;
        for(ll i = 0; i < n; i++){
            cin >> a[i];
            s.insert(i);
        }
        queue<int> q;
        for(ll i = 0; i < n; i++){
            if(gcd(a[i], a[(i+1)%n]) == 1ll){
                q.push(i);
            }
        }
        vector<ll> res;
        while(!q.empty()){
            ll temp = q.front();
            q.pop();
            if(s.find(temp) == s.end()){
                continue;
            }
            auto it = s.upper_bound(temp);
            ll nxt = it==s.end() ? *s.begin() : *it;
            if(gcd(a[temp], a[nxt]) > 1ll){
                continue;
            }
            res.emplace_back(nxt);
            s.erase(nxt);
            q.push(temp);
        }
        cout << (int)res.size() << " ";
        for(auto it: res){
            cout << it+1 << " ";
        }
        cout << "\n";
    }
    return 0;
}

