#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> st1, st2;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    st1.push_back(0);
    st2.push_back(0);
    for(ll i = 0; i < n; i++){
        if(st1.back() != a[i] && st2.back() != a[i]){
            if(i < n-1){
                if(a[i+1] == st1.back()){
                    st1.emplace_back(a[i]);
                }
                else{
                    st2.emplace_back(a[i]);
                }
            }
            else{
                st1.emplace_back(a[i]);
            }
        }
        else if(st1.back() == a[i]){
            st2.emplace_back(a[i]);
        }
        else if(st2.back() == a[i]){
            st1.emplace_back(a[i]);
        }
    }
    ll res = 0;
    for(ll i = 1; i < (ll)st1.size(); i++){
        if(st1[i] != st1[i-1]){
            res++;
        }
    }
    for(ll i = 1; i < (ll)st2.size(); i++){
        if(st2[i] != st2[i-1]){
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
