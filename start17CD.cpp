#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

pair<int, int> findInv(string &s){
    int cnt1 = 0;
    int res = 0;
    for(int i = 0; i < (int)s.length(); i++){
        if(s[i] == '1'){
            cnt1++;
        }
        else{
            res += cnt1;
        }
    }
    return {res, cnt1};
}

bool all(string &s){
    int cnt = 0;
    for(int i = 0; i < (int)s.length(); i++){
        cnt += s[i] == '0';
    }
    return cnt == 0 || cnt == (int)s.length();
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<int, string> > v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i].second;
            int cnt = 0;
            for(int j = 0; j < m; j++) cnt += v[i].second[j] == '0';
            v[i].first = -cnt;
        }
        sort(v.begin(), v.end());
        string s = "";
        for(int i = 0; i < n; i++) s += v[i].second;
        int cnt1 = 0;
        int res = 0;
        for(int i = 0; i < (int)s.length(); i++){
            if(s[i] == '1'){
                cnt1++;
            }
            else{
                res += cnt1;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
