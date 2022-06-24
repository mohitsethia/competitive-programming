#include<iostream>
#include<vector>
#include<climits>
#include<string>
#include<map>
#include<algorithm>
#include<set>
using namespace std;
#define int long long
#define mk make_pair
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int k = n;
        vector<pair<int, int> > val;
        for(int i = 2; i * i <= n; i++){
            int cnt = 0;
            while(n%i == 0){
                n /= i;
                cnt++;
            }
            if(cnt > 0){
                val.push_back(mk(cnt, i));
            }
        }
        if(n > 1){
            val.push_back(mk(1, n));
        }
        sort(val.rbegin(), val.rend());
        vector<int> ans(val[0].first, val[0].second);
        for(int i = 1; i < (val.size()); i++){
            for(int j = 0; j < val[i].first; j++){
                ans.back() *= val[i].second;
            }
        }
        cout << ans.size() << endl;
        for(auto it : ans){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
