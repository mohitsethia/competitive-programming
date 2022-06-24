#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<map>
#include<set>

#define int long long
using namespace std;

const int MAXN = 2e5+1;
vector<pair<int, int> > t(4*MAXN);

pair<int, int> findMax(pair<int, int> a, pair<int, int> b){
    if(a.first > b.first) return a;
    else return b;
}

void build(vector<pair<int, int> > &a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v].first = a[tl].first;
        t[v].second = a[tl].second;
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = findMax(t[v*2], t[v*2+1]);
    }
}


pair<int, int> query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return {0, 0};
    if (l <= tl && r >= tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return findMax(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v].first = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = findMax(t[v*2], t[v*2+1]);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t = 1;
    // cin >> t;
    // while(t--){
        int n, k;
        cin >> n >> k;
        vector<pair<int, int> > a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i].first;
            a[i].second = i;
        }
        build(a, 1, 0, n-1);
        set<int> s;
        vector<int> takenBy(n);
        int toggle = 1;
        while((int)s.size() < n){
            pair<int, int> temp = t[1];
            if(s.find(temp.second) != s.end()){
                update(1, 0, n-1, temp.second, 0);
                continue;
            }
            int cnt = 0;
            s.insert(temp.second);
            takenBy[temp.second] = toggle;
            int total = 0;
            while(total != k){
                if(temp.second-cnt-1 == -1) break;
                if(s.find(temp.second-cnt-1) != s.end()){
                    cnt++;
                    continue;
                }
                s.insert(temp.second-cnt-1);
                update(1, 0, n-1, temp.second-cnt-1, 0);
                takenBy[temp.second-cnt-1] = toggle;
                total++;
                cnt++;
            }
            cnt = 0;
            total = 0;
            while(total != k){
                if(temp.second+cnt+1 == n) break;
                if(s.find(temp.second+cnt+1) != s.end()){
                    cnt++;
                    continue;
                }
                s.insert(temp.second+cnt+1);
                update(1, 0, n-1, temp.second+cnt+1, 0);
                takenBy[temp.second+cnt+1] = toggle;
                total++;
                cnt++;
            }
            toggle = toggle == 1 ? 2 : 1;
        }
        for(int i = 0; i < n; i++){
            cout << takenBy[i];
        }
    // }
    return 0;
}
