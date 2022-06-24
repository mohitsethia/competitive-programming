#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
public:
    int minFallingPathSum(vector<vector<int> > &matrix){
        int n = matrix.size();
        int m = n ? matrix[0].size() : 0;
        if(n == 1 && m == 1) return matrix[0][0];
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                int option1 = j-1 >= 0 ? matrix[i-1][j-1] : INT_MAX;
                int option2 = matrix[i-1][j];
                int option3 = j+1 < m ? matrix[i-1][j+1] : INT_MAX;
                matrix[i][j] += min(option1, min(option2, option3));
            }
        }
        int mn = INT_MAX;
        for(int i = 0; i < m; i++){
            mn = min(mn, matrix[n-1][i]);
        }
        return mn;
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int> > matrix(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    Solution *obj = new Solution();
    cout << obj->minFallingPathSum(matrix) << "\n";
    return 0;
}
