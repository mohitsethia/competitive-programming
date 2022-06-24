#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<climits>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
//    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > min_heap;
//    priority_queue<pair<int, int> > max_heap;
    int cnt = 1;
    set<pair<int, int> > s, p;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int m;
            cin >> m;
            s.insert({m, cnt});
            p.insert({cnt, m});
            cnt++;
        }
        else if(t == 3){
            auto it = *s.rbegin();
            int mx = it.first;
            auto x = s.lower_bound({mx, INT_MIN});
            int i = (x->second);
            cout << i << " ";
            s.erase(x);
            p.erase({i, mx});
        }
        else{
            auto it = *p.begin();
            int i = it.first;
            int mx = it.second;
            cout << i << " ";
            p.erase(it);
            s.erase({mx, i});
        }
    }
    return 0;
}
