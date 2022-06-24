#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;

class Solution{
    int needed(vector<int> &a, double d){
        int res = 0;
        for(int i = 0; i < (int)a.size()-1; i++){
            res += ceil((a[i+1]-a[i])/(d*1.0)) - 1;
        }
        return res;
    }

    public:

    double findMaxDist(vector<int> &a, int canPut){
        int n = a.size();
        double low = 0;
        double high = a[n-1] - a[0];
        while(high - low >= 1e-6){
            double mid = (high+low)/2.0;
            int stations = needed(a, mid);
            if(stations > canPut){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        return high;
    }
};

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    Solution obj;
    cout << fixed << setprecision(3) << obj.findMaxDist(a, k) << "\n";
    return 0;
}
