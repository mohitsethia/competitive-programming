#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        string p = s;
        sort(p.begin(), p.end());
        if(p == s){
            cout << "0\n";
            continue;
        }
        int mn = 1e6;
        int mx = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') mx = max(mx, i);
            else mn = min(mn, i);
        }
        int l = mn, r = mx;
        vector<int> ans;
        while(l < r){
            ans.push_back(l);
            ans.push_back(r);
            l++, r--;
            while(l < n && s[l] == '0') l++;
            while(r >= 0 && s[r] == '1') r--;
        }
        sort(ans.begin(), ans.end());
        cout << "1\n" << ans.size() << " ";
        for(auto i: ans)
            cout << i+1 << " ";
        cout << "\n";
    }
    return 0;
}
