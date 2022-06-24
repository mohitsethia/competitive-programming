#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>

#define int long long
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int> > slots(n+1);
    priority_queue<pair<int, vector<int> > > pq;
    vector<int> build;
    set<vector<int> > done_builds;
    int val = 0;
    for(int i = 1; i <= n; i++){
        slots[i].push_back(0);
        int ci;
        cin >> ci;
        while(ci--){
            int x;
            cin >> x;
            slots[i].push_back(x);
        }
        build.push_back(slots[i].size() -1);
        val += slots[i].back();
    }
    pq.push({val, build});
    set<vector<int> > banned;
    int m;
    cin >> m;
    while(m--){
        vector<int> v(n);
        for(int &bi: v){
            cin >> bi;
        }
        banned.insert(v);
    }
    while(banned.count(pq.top().second)){
        val = pq.top().first;
        vector<int> b = pq.top().second;
        pq.pop();
        for(int i = 0; i < n; i++){
            if(b[i] > 1){
                int new_val = val - slots[i+1][b[i]] + slots[i+1][b[i]-1];
                b[i]--;
                if(!done_builds.count(b)){
                    pq.push({new_val, b});
                    done_builds.insert(b);
                }
                b[i]++;
            }
        }
    }
    build = pq.top().second;
    for(int bi: build){
        cout << bi << " ";
    }
    return 0;
}
