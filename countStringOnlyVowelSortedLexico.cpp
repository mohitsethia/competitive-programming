#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int N = 1e6+1;

class Solution{
    vector<int> dp;
    public:
    void preprocess(){
        dp = vector<int>(N);
        dp[1] = 5;
        vector<int> count(5, 1);
        for(int i = 2; i < N; i++){
            for(int j = 3; j >= 0; j--){
                count[j] += count[j+1];
            }
            for(int c: count){
                dp[i] += c;
                dp[i] %= MOD;
            }
        }
    }
    int findNumberOfString(int n){
        return dp[n];
    }
};

int32_t main(){
    int t;
    cin >> t;
    Solution *obj = new Solution();
    obj->preprocess();
    while(t--){
        int n;
        cin >> n;
        cout << obj->findNumberOfString(n) << "\n";
    }
    return 0;
}
