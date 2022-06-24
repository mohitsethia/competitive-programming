#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution{
public:
    int shortestSubarray(vector<int> nums, int k){
        int n = nums.size();
        int res = n+1;
        deque<int> dq;
        for(int i = 0; i < n; i++){
            if(i > 0){
                nums[i] += nums[i-1];
            }
            if(nums[i] >= k){
                res = min(res, i+1);
            }
            while(dq.size() > 0 && nums[i]-nums[dq.front()] >= k){
                res = min(res, i-dq.front());
                dq.pop_front();
            }
            while(dq.size() > 0 && nums[i] <= nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return res <= n ? res : -1;
    }
};

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    Solution *obj = new Solution();
    cout << obj->shortestSubarray(nums, k) << "\n";
    return 0;
}
