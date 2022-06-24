#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<unordered_map>
#include<cstring>
#include<numeric>
#include<cmath>
using namespace std;
#define int long long
#define MOD 1000000007
int numSubmatrixSumTarget(vector<vector<int> >& A, int target){
    int res = 0, m = A.size(), n = A[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            A[i][j] += A[i][j-1];
        }
    }
    unordered_map<int, int> counter;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            counter = {{0, 1}};
            int cur = 0;
            for(int k = 0; k < m; k++){
                cur += A[k][j] - (i > 0 ? A[k][i-1] : 0);
                res += (counter.find(cur-target) != counter.end() ? counter[cur-target] : 0)%MOD;
                counter[cur]++;
            }
        }
    }
    return res%MOD;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int> > A(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> A[i][j];
            }
        }
        cout << numSubmatrixSumTarget(A, k) << endl;
    }
    return 0;
}
