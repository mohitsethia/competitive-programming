#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<set>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    map<int, set<int> > mp;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        mp[a].insert(b);
        mp[b].insert(a);
    }
    int ans = 0;
    bool flag = true;
    while(flag){
        flag =  false;
        set<pair<int, int> > free;
        for(auto it: mp){
            if(it.second.size() == 1){
                free.insert({it.first, *it.second.begin()});
            }
        }
        if(free.size() > 0){
            ans++;
            for(auto it: free){
                mp[it.first].erase(it.second);
                mp[it.second].erase(it.first);
            }
            flag = true;
        }
    }
    cout << ans << "\n";
    return 0;
}
