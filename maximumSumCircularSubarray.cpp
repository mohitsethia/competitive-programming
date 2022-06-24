#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

class Solution{
    public:
    int maxSubarrayCircularSum(vector<int> &nums){
        int n = nums.size();
        int temp_min_sum = 0;
        int globalMin = INT_MAX;
        int temp_max_sum = 0;
        int globalMax = INT_MIN;
        int totalSum = 0;
        for(int i = 0; i < n; i++){
            totalSum += nums[i];

            temp_max_sum += nums[i];
            globalMax = max(globalMax, temp_max_sum);
            if(temp_max_sum < 0) temp_max_sum = 0;

            temp_min_sum += nums[i];
            globalMin = min(globalMin, temp_min_sum);
            if(temp_min_sum > 0) temp_min_sum = 0;
        }
        if(totalSum == globalMin) return globalMax;
        return max(totalSum-globalMin, globalMax);
    }
};

int main(){
    int t;
    cin >> t;
    Solution obj;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        cout << obj.maxSubarrayCircularSum(nums) << "\n";
    }
    return 0;
}
