#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

#define int long long
#define mp make_pair
using namespace std;

// bool cmp(pair<int, pair<int, int> > &a, pair<int, pair<int, int> > &b){
    // if(a.first == b.first){
        // return a.second.first > b.second.first;
    // }
    // return a.first < b.first;
// }

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        auto cmp = [](const pair<int, pair<int, int> > &a, const pair<int, pair<int, int> > &b){
            if(a.first == b.first) return a.second.first > b.second.first;
            return a.first < b.first;
        };
        set<pair<int, pair<int, int> >, decltype(cmp) > s(cmp);
        s.insert(mp(n, mp(1ll, n)));
        vector<int> a(n+1);
        int cnt = 1;
        while(!s.empty()){
            auto it = s.end();
            it--;
            auto temp = *it;
            s.erase(it);
            int l = temp.second.first;
            int r = temp.second.second;
            int idx;
            if((r-l+1)%2) idx = (r+l)/2;
            else idx = (r+l-1)/2;
            a[idx] = cnt++;
            if(r > idx){
                s.insert({r-idx+1, {idx+1, r}});
            }
            if(l < idx){
                s.insert({idx-l+1, {l, idx-1}});
            }
        }
        for(int i = 1; i <= n; i++){
            cout << a[i] << " \n"[i == n];
        }
    }
    return 0;
}
