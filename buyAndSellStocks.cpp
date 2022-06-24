#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
    public:
    int MaxProfit(vector<int> &prices, int k){
        int n = prices.size();

        //Case-1: n <= 1 || k == 0
        if(k == 0 || n <= 1) return 0;

        //Case-2: k >= n
        if(2*k > n){
            int res = 0;
            for(int i = 1; i < n; i++){
                if(prices[i] > prices[i-1])
                    res += prices[i]-prices[i-1];
            }
            return res;
        }

        //Case-3: 1 <= k < n
        vector<int> dp(2*n+1);
        dp[0] = -prices[0];
        for(int i = 1; i <= 2*k; i++){
            if(i%2 == 0) dp[i] = INT_MIN;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= 2*k; j++){
                if(j == 0) dp[j] = max(dp[j], -prices[i]);
                else if(j%2 == 0){ // buy
                    dp[j] = max(dp[j], dp[j-1]-prices[i]);
                }
                else{ // sell
                    dp[j] = max(dp[j], dp[j-1]+prices[i]);
                }
            }
        }
        return dp[2*k-1];
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int k;
    cin >> k;
    Solution *obj = new Solution();
    cout << obj->MaxProfit(nums, k) << "\n";
    return 0;
}
