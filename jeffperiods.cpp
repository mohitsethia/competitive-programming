#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define int long long
int32_t main(){
    int n, x, k;
    cin >> n;
    map<int, vector<int> > mp;
    for(int i = 0; i < n; i++){
        cin >> x;
        mp[x].push_back(i);
    }
    vector<pair<int, int>> v;
    map<int, vector<int>>::iterator p = mp.begin();
    while(p != mp.end()){
        k = p->first;
        if(mp[k].size() == 1){
            v.push_back({k, 0});
        }
        else{
            set<int> s;
            for(int i = 1; i < mp[k].size(); i++){
                s.insert(abs(mp[k][i]-mp[k][i-1]));
            }
            set<int>::iterator q = s.begin();
            if(s.size() == 1){
                v.push_back({k, *q});
            }
        }
        p++;
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}
