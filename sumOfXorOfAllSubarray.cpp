#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int findXorSum(vector<int> &a){
        int n = a.size();
        int sum = 0;
        int powerOf2 = 1;
        for(int i = 0; i < 31; i++){
            int c_odd = 0;
            bool odd = false;
            for(int j = 0; j < n; j++){
                if((a[j]&(1 << i)) > 0){
                    odd = !odd;
                }
                if(odd){
                    c_odd++;
                }
            }
            for(int j = 0; j < n; j++){
                sum += (powerOf2*c_odd);
                if((a[j]&(1 << i)) > 0){
                    c_odd = (n-j-c_odd);
                }
            }
            powerOf2 *= 2;
        }
        return sum;
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
    cout << obj.findXorSum(a) << "\n";
    return 0;
}
