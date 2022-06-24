#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
using namespace std;
int countDistinct(vector<char> &u, vector<char> &v){
    set<char> s(u.begin(), u.end());
    int cnt = 0;
    for(auto i: v){
        if(s.find(i) != s.end()){
            cnt++;
        }
    }
    return cnt;
}
void solve(){
    int n;
    scanf("%d", &n);
    map<string, vector<char> > mp;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        mp[s.substr(1)].push_back(s[0]);
    }
    int cnt = 0;
    for(auto i: mp){
        for(auto j: mp){
            if(i.first != j.first){
                int temp = countDistinct(i.second, j.second);
                cnt += (i.second.size()-temp)*(j.second.size()-temp);
            }
        }
    }
    printf("%d\n", cnt);
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}

