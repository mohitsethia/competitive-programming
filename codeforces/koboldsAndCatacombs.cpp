#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
using ll = long long;
ll countGroups(vector<ll> &a){
    if((ll)a.size() < 2){
        return (ll)a.size();
    }
    stack<ll> s;
    s.push(a[0]);
    for(ll i = 1; i < (ll)a.size(); i++){
        if(a[i] >= s.top()){
            s.push(a[i]);
        }
        else{
            ll last = s.top();
            s.pop();
            while((ll)s.size() > 0 && a[i] < s.top()){
                s.pop();
            }
            s.push(last);
        }
    }
    return (ll)s.size();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << countGroups(a) << "\n";
    return 0;
}
