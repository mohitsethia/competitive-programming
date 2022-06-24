#include <iostream>
#include <algorithm>

using namespace std;

int solve(vector<vector<char>> &mat, int k) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> col(m);
    int tot = 0;
    for(int j = 0; j < m; j++) {
        int ret = 0;
        int first = -1;
        int f = 0;
        int t = 0;
        for(int i = 0; i < n; i++) {
            if(mat[i][j] == '#') {
                if(first == -1) {
                    f = i;
                } else {
                    first = 0;
                    ret += i-f;
                }
                t++;
            }
        }
        if(t == 1) ret = 1;
        tot += t;
        ret *= t;
        if(t > 1)
            ret /= 2;
        col[j] = ret;
    }
    int sum = 0;
    if(tot == 0) return sum;
    int r = col[0];
    for(int i = 1; i <= k; i++) {
        if(col[i] != 0)
            r *= (col[i]+1);
    }
    sum = max(sum, r);
    for(int i = k+1; i < m; i++) {
        if(col[i-k] != 0)
            r /= (col[i-k]+1);
        if(col[i] != 0)
            r *= (col[i]+1);
        sum = max(sum, r);
    }
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    int k;
    cin >> k;
    cout << solve(mat, k);
    return 0;
}
