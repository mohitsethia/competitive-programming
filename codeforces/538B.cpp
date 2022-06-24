#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> quasi;
const int N = (int)1e6 + 5;
void preCompute(int x, int len){
    if(len > 6) return;
    quasi.emplace_back(x);
    preCompute(x*10, len+1);
    preCompute(x*10+1, len+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    quasi.emplace_back(1);
    preCompute(1, 0);
    int n;
    cin >> n;
    int sz = quasi.size();
    vector<int> dp(n+1, N), used(n+1, -1), ans;
    dp[0] = 0;
    for(auto qbi: quasi){
        for(int j = qbi; j <= n; j++){
            if(dp[j] > dp[j-qbi] + 1){
                dp[j] = dp[j-qbi] + 1;
                used[j] = qbi;
            }
        }
    }
    while(used[n] > -1){
        ans.emplace_back(used[n]);
        n -= used[n];
    }
    cout << (int)ans.size() << endl;
    for(auto &it: ans){
        cout << it << " ";
    }
    return 0;
}
