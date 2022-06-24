#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<set>

using namespace std;

int upperBound(const vector<int> &nums, vector<int> &incSub, int pos, int len){
    int low = 1;
    int high = len;
    while(low <= high){
        int mid = (low+high+1)/2;
        if(nums[incSub[mid]] <= nums[pos]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}

vector<int> LIS(const vector<int> &nums){
    int len = 0;
    vector<int> par(nums.size()), incSub(nums.size()+1);
    for(int i = 0; i < nums.size(); i++){
        int idx = upperBound(nums, incSub, i, len);
        par[i] = incSub[idx-1];
        incSub[idx] = i;
        len = max(len, idx);
        // cout << idx << " " << len << "\n";
    }
    vector<int> subs(len);
    int k = incSub[len];
    for(int i = len-1; i >= 0; i--){
        subs[i] = nums[k];
        k = par[k];
    }
    return subs;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> res = LIS(a);
    cout << res.size() << "\n";
    for(int i: res) cout << i << " ";
    cout << "\n";
    return 0;
}
