#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<pair<ll, ll> > light(n);
    for(int i = 0; i < n; i++){
        cin >> light[i].first;
    }
    for(int i = 0; i < n; i++){
        cin >> light[i].second;
    }
    ll ans = LLONG_MAX;
    bool found = false;
    for(int i = 1; i < n-1; i++){
        ll mn1 = LLONG_MAX;
        int idx = -1;
        for(int j = 0; j < i; j++){
            if(light[j].first < light[i].first){
                if(light[j].second < mn1){
                    mn1 = light[j].second;
                    idx = j;
                }
            }
        }
        if(idx == -1) continue;
        ll mn2 = LLONG_MAX;
        idx = -1;
        for(int k = i+1; k < n; k++){
            if(light[k].first > light[i].first){
                if(mn2 > light[k].second){
                    mn2 = light[k].second;
                    idx = k;
                }
            }
        }
        if(idx == -1) continue;
        found = true;
        ans = min(ans, mn1+light[i].second+mn2);
    }
    if(found){
        cout << ans << endl;
    }
    else{
        cout << "-1\n";
    }
    return 0;
}
