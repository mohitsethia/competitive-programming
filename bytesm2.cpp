#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
//int maxStone(int n, int m, vector<vector<int> > &mat, int i, int j){
//    if(i >= n || j < 0 || j >= m){
//        return 0;
//    }
//    return (mat[i][j] + max(maxStone(n, m, mat, i+1, j), max(maxStone(n, m, mat, i+1, j-1), maxStone(n, m, mat, i+1, j+1))));
//}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > arr(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    int stones = 0;
//    for(int i = 0; i < m; i++){
//        stones = max(stones, maxStone(n, m, mat, 0, i));
//    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(j>0 && j<m-1)
                arr[i][j] = max(arr[i-1][j] + arr[i][j] , max(arr[i-1][j-1]+arr[i][j] , arr[i-1][j+1]+arr[i][j]));
            else if(j>0)
                arr[i][j] = max(arr[i-1][j]+arr[i][j] ,arr[i-1][j-1]+arr[i][j]);
            else if(j<m-1)
                arr[i][j] = max(arr[i-1][j]+arr[i][j],arr[i-1][j+1]+arr[i][j]);
        }
    }
    for(int i = 0; i < m; i++){
        stones = max(stones, arr[n-1][i]);
    }
    cout << stones << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
