#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
    public:
    int getTotalXorOfSubarrayXors(vector<int> &a){
        int res = 0;
        int n = a.size();
        for(int i = 0; i < n; i++){
            int freq = (i+1)*(n-i);
            if(freq%2){
                res ^= a[i];
            }
        }
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    Solution obj;
    cout << obj.getTotalXorOfSubarrayXors(a) << "\n";
    return 0;
}
