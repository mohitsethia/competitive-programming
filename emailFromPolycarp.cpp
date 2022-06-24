#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
vector<pair<char, int> > split(string &str){
    int cnt = 1;
    char c = str[0];
    vector<pair<char, int> > res;
    int n = (int)str.length();
    for(int i = 1; i <= n; i++){
        if(str[i] == c){
            cnt++;
        }
        else{
            res.push_back({c, cnt});
            cnt = 1;
            c = str[i];
        }
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        string s, t;
        cin >> s >> t;
        int n = (int)s.length();
        int m = (int)t.length();
        vector<pair<char, int> > sa = split(s);
        vector<pair<char, int> > ta = split(t);
        bool ok = (sa.size() == ta.size());
        if(ok){
            for(int i = 0; i < (int)sa.size(); i++){
                if(sa[i].first != ta[i].first || sa[i].second > ta[i].second){
                    ok = false;
                    break;
                }
            }
        }
        if(ok) puts("YES");
        else puts("NO");
    }
    return 0;
}
