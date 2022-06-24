#include<iostream>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

#define int long long

int32_t main(){
    int n;
    cin >> n;
    map<int, int> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        m[a[i]]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int> > > pq;
    for(auto it: m){
        pq.push({it.second, it.first});
    }
    vector<vector<int > > res;
    while(pq.size() >= 3){
        pair<int, int> p = pq.top();
        pq.pop();
        pair<int, int> q = pq.top();
        pq.pop();
        pair<int, int> r = pq.top();
        pq.pop();
        p.first--;
        q.first--;
        r.first--;
        vector<int> ct = {p.second, q.second, r.second};
        sort(ct.rbegin(), ct.rend());
        res.push_back(ct);
        if(p.first) pq.push(p);
        if(q.first) pq.push(q);
        if(r.first) pq.push(r);
    }
    cout << res.size() << "\n";
    for(auto i: res){
        for(auto j: i){
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
