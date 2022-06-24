#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution{
    public:
    int CountSubarraysWithXorK(vector<int> &nums, int k){
        unordered_map<int, int> freq;
        int Xor = 0;
        int count = 0;
        for(int i = 0; i < (int)nums.size(); i++){
            Xor ^= nums[i];
            if(Xor == k) count++;
            if(freq.count(Xor^k)){
                count += freq[Xor^k];
            }
            freq[Xor]++;
        }
        return count;
    }
};

int main(){
    int testCase;
    cin >> testCase;
    Solution obj;
    while(testCase--){
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        cout << obj.CountSubarraysWithXorK(nums, k) << "\n";
    }
    return 0;
}
