#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        string s;
        cin >> n >> m >> s;
        auto value = [&](char ch) -> int{
            return ch == '+' ? +1 : -1;
        };
        vector<int> pre(n+1), pre_max(n+1), pre_min(n+1);
        for(int i = 0; i < n; i++){
            pre[i+1] = pre[i] + value(s[i]);
            pre_max[i+1] = max(pre_max[i], pre[i+1]);
            pre_min[i+1] = min(pre_min[i], pre[i+1]);
        }
        vector<int> suff(n+1), suff_max(n+1), suff_min(n+1);
        for(int i = n-1; i >= 0; i--){
            suff[i] = value(s[i]) + suff[i+1];
            suff_max[i] = max(0, value(s[i])+suff_max[i+1]);
            suff_min[i] = min(0, value(s[i])+suff_min[i+1]);
        }
        while(m--){
            int l, r;
            cin >> l >> r;
            int mx = max(pre_max[l-1], pre[l-1]+suff_max[r]);
            int mn = min(pre_min[l-1], pre[l-1]+suff_min[r]);
            cout << mx-mn+1 << "\n";
        }
    }
    return 0;
}
