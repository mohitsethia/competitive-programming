#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

#define int long long

int32_t main(){
    int n;
    cin >> n;
    vector<pair<int, int> > a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    vector<int> p;
    set<int> done;
    p.push_back(1);
    done.insert(1);
    int i = 1;
    while((int)p.size() < n){
        int cf = a[i].first;
        int cs = a[i].second;
        if(a[cf].first == cs || a[cf].second == cs && !done.count(cf)){
            p.push_back(cf);
            done.insert(cf);
            i = cf;
        }
        else if(a[cs].first == cf || a[cs].second == cf && !done.count(cs)){
            p.push_back(cs);
            done.insert(cs);
            i = cs;
        }
        else if(done.count(cf) && done.count(cs)) break;
        else if(done.count(cf)){
            done.insert(cs);
            p.push_back(cs);
            i = cs;
        }else{
            done.insert(cf);
            p.push_back(cf);
            i = cf;
        }
    }
    for(int i: p) cout << i << " ";
    return 0;
}
