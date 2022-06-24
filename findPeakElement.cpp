#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
class Solution{
public:
    int findPeakElement(vector<int>& nums){
        int low = 0, high = nums.size()-1;
        while(low < high){
            int mid = (low+high)/2;
            if(nums[mid] < nums[mid+1]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> elements(n);
    for(int i = 0; i < n; i++){
        cin >> elements[i];
    }
    Solution st;
    cout << st.findPeakElement(elements) << "\n";
    return 0;
}
