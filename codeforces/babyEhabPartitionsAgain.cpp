#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
bool canPartition(vector<int>& nums, int target){
    vector<vector<int> > dp(nums.size(), vector<int>(target+1));
    for(int i = 0; i < nums.size(); i++){
        dp[i][0] = true;
    }
    for(int j = 1; j <= target; j++){
        if(nums[0] == j){
            dp[0][j] = true;
            break;
        }
    }
    for(int i = 1; i < nums.size(); i++){
        for(int j = 1; j <= target; j++){
            if(nums[i] == j){
                dp[i][j] = true;
            }
            else if(nums[i] <= j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[nums.size()-1][target];
}
int main(){
    int n;
    cin >> n;
    int sum = 0;
    vector<int> nums(n+1);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        sum += nums[i];
    }
    if(sum%2){
        cout << 0 << endl;
        return 0;
    }
    if(!canPartition(nums, sum/2)){
        cout << 0 << endl;
        return 0;
    }
    while(1){
        for(int i = 0; i < n; i++){
            if(nums[i]%2){
                cout << 1 << endl << i+1 << endl;
                return 0;
            }
            else{
                nums[i] /= 2;
            }
        }
    }
    return 0;
}
