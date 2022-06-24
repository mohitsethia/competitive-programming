#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<climits>

#define int long long
using namespace std;

int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<int> have(n+1), want(m+1);
    for(int i = 1; i <= n; i++){
        cin >> have[i];
    }
    multiset<int> need, extra;
    for(int i = 1; i <= m; i++){
        cin >> want[i];
        for(int j = 1; j <= want[i]; j++){
            need.insert(i);
        }
    }
    int L = 1;
    int ans = INT_MAX;
    for(int R = 1; R <= n; R++){
        if(need.find(have[R]) != need.end()){
            need.erase(need.find(have[R]));
        }
        else{
            extra.insert(have[R]);
        }
        if(!need.empty()) continue;
        while(extra.find(have[L]) != extra.end()){
            extra.erase(extra.find(have[L]));
            L++;
        }
        ans = min(ans, (int)extra.size());
    }
    if(ans == INT_MAX) ans = -1;
    cout << ans  << "\n";
    return 0;
}
