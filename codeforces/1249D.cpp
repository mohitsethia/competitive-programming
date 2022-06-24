#include<iostream>
#include<algorithm>
#include<set>
#include<vector>

#define int long long
using namespace std;
const int N = 2e5+5;

signed main(){
    int n, k;
    cin >> n >> k;
    vector<int> l(n), r(n);
    vector<int> in[N], out[N];
    int mx = -1;
    for(int i = 0; i < n; i++){
        cin >> l[i] >> r[i];
        mx = max(mx, l[i]+2);
        mx = max(mx, r[i]+2);
        in[l[i]].push_back(i);
        out[r[i]+1].push_back(i);
    }
    vector<int> ans;
    set<pair<int, int> > st;
    for(int i = 0; i < mx; i++){
        for(auto x: in[i]){
            st.insert({r[x], x});
        }
        for(auto x: out[i]){
            st.erase({r[x], x});
        }
        while((int)st.size() > k){
            auto it = st.end();
            it--;
            ans.push_back(it->second);
            st.erase(it);
        }
    }
    cout << (int)ans.size() << "\n";
    for(int i = 0; i < (int)ans.size(); i++){
        cout << ans[i]+1 << " ";
    }
    return 0;
}
