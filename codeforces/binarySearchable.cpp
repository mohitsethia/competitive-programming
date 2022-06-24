#include<iostream>
#include<algorithm>
#include<climits>
#include<string>
#include<sstream>

using namespace std;

class Solution{
    public:
    int binarySearchable(vector<int> &nums){
        int n = nums.size();
        vector<int> max_left(n);
        max_left[0] = nums[0];
        for(int i = 1; i < n; i++){
            max_left[i] = max(max_left[i-1], nums[i]);
        }
        int min_right = INT_MAX;
        int count = 0;
        for(int i = n-1; i >= 0; i--){
            min_right = min(min_right, nums[i]);
            if(nums[i] >= max_left[i] && nums[i] <= min_right){
                count++;
            }
        }
        return count;
    }
};

int main(){
    Solution obj;
    string line;
    while(getline(cin, line) &&!line.empty()){
        vector<int> nums;
        if(line.back() == ']'){
            line.pop_back();
            if(line.back() == ' ') line.pop_back();
            reverse(line.begin(), line.end());
            line.pop_back();
            if(line.back() == ' ') line.pop_back();
            reverse(line.begin(), line.end());
        }
        stringstream ss(line);
        int i;
        while(ss >> i){
            nums.push_back(i);
            if(ss.peek() == ',' || ss.peek() == ' ') ss.ignore();
        }
        cout << obj.binarySearchable(nums) << "\n";
    }
    return 0;
}
