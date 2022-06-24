#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, s, f;
    cin >> n >> m >> s >> f;
    map<ll, pair<ll, ll> > mp;
    ll t, l, r;
    for(ll i = 0; i < m; i++){
        cin >> t >> l >> r;
        mp[t] = {l, r};
    }
    bool left = false;
    if(f < s) left = true;
    ll d = abs(f-s);
    ll i = 0, cnt = 0;
    while(cnt < d){
        i++;
        if(mp.find(i) == mp.end()){
            if(left){
                cout << 'L';
                s--;
            }
            else{
                cout << 'R';
                s++;
            }
            cnt++;
        }
        else{
            if(left){
                l = mp[i].first;
                r = mp[i].second;
                if(s <= r+1 && s >= l){
                    cout << 'X';
                }
                else{
                    cout << 'L';
                    s--;
                    cnt++;
                }
            }
            else{
                l = mp[i].first;
                r = mp[i].second;
                if(s <= r && s >= l-1){
                    cout << 'X';
                }
                else{
                    cout << 'R';
                    s++;
                    cnt++;
                }
            }
        }
    }
    return 0;
}























/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
#define int long long
int32_t main(){
    int n, m, s, f;
    cin >> n >> m >> s >> f;
    map<int, int> l, r;
    for(int i = 0; i < m; i++){
        int t, a, b;
        cin >> t >> a >> b;
        l[t] = a;
        r[t] = b;
    }
    for(int i = 1; ;i++){
        if(s == f){
            break;
        }
        if(s < f){
            if(l[i] <= s && r[i] >= s){
                cout << "X";
            }
            else if(s+1 >= l[i] && s+1 <= r[i]){
                cout << "X";
            }
            else{
                cout << "R";
                s++;
            }
        }
        else{
            if(l[i] <= s && s <= r[i]){
                cout << "X";
            }
            else if(s-1 >= l[i] && s-1 <= r[i]){
                cout << "X";
            }
            else{
                cout << "L";
                s--;
            }
        }
    }
    return 0;
}
*/
