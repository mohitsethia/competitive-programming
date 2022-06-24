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
        string s;
        cin >> s;
        int n = s.length();
        vector<pair<ll, ll> > v;
        int i = 0;
        while(i < n){
            int j = i;
            if(i < n-1 && s[i] != '?'){
                if(s[i] == s[i+1])
                    v.push_back({i, i+1});
                i++;
                continue;
            }
            else if(i == n-1){
                break;
            }
            while(j < n && s[j] == '?'){
                j++;
            }
            if(i == 0 || j == n){
                i = j;
                continue;
            }
            int st = i-1;
            int end = j;
            int cnt = j-i;
            if(cnt&1){
                if(s[st] != s[end]){
                    v.push_back({st, end});
                }
            }
            else{
                if(s[st] == s[end]){
                    v.push_back({st, end});
                }
            }
            i = j;
        }
        sort(v.begin(), v.end());
        ll prev = 0, ans = 0;
        for(auto x: v){
            ans -= (x.second-x.first)*(x.second-x.first-1)/2;
            ans += (x.second-1-(prev-1))*(x.second-1-(prev-1-1))/2;
            prev = x.first+1;
        }
        ans += (n-1-(prev-1))*(n-1-(prev-1-1))/2;
        cout << ans << endl;
    }
    return 0;
}
