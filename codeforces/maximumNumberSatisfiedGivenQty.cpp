// https://www.geeksforgeeks.org/maximum-number-customers-can-satisfied-given-quantity/

#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, d;
    cin >> n >> d;
    int a, b;
    cin >> a >> b;
    vector<vector<int> > cust(n, vector<int>(2));
    for(int i = 0; i < n; i++){
        cin >> cust[i][0] >> cust[i][1];
    }
    vector<pair<int, int> > res;
    for(int i = 0; i < n; i++){
        int p = cust[i][0], q = cust[i][1];
        res.push_back({p*a + q*b, i+1});
    }
    sort(res.begin(), res.end());
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(res[i].first <= d){
            d -= res[i].first;
            ans.push_back(res[i].second);
        }
    }
    cout << (int)ans.size() << "\n";
    for(int i = 0; i < (int)ans.size(); i++){
        cout << ans[i] << " \n"[i == (int)ans.size()-1];
    }
    return 0;
}
