#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

#define int long long

class Solution{
    vector<vector<int> > dp;
    int matrixChain(vector<int> &p, int i, int j){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int cnt = INT_MAX;
        for(int k = i; k < j; k++){
            cnt = min(cnt, matrixChain(p, i, k) + matrixChain(p, k+1, j) + p[i-1]*p[k]*p[j]);
        }
        return dp[i][j] = cnt;
    }
    public:
        int matrixChain(vector<int> &p){
            dp = vector<vector<int> >(100, vector<int>(100, -1));
            return matrixChain(p, 1, p.size()-1);
        }
};

int32_t main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++)
        cin >> p[i];

    Solution *obj = new Solution();

    cout << obj->matrixChain(p) << "\n";
    return 0;
}
