#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
    public:
    vector<int> meanderingArray(vector<int> &nums){
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size()-1;
        int n = nums.size();
        vector<int> result(n);
        int k = 0;
        int toggle = 1;
        while(i <= j){
            if(toggle){
                result[k++] = nums[j--];
            }
            else{
                result[k++] = nums[i++];
            }
            toggle ^= 1;
        }
        return result;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    Solution *obj = new Solution();
    vector<int> res = obj->meanderingArray(nums);
    for(int i = 0; i < (int)res.size(); i++){
        cout << res[i] << " \n"[i == (int)res.size()-1];
    }
    return 0;
}
