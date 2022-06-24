#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    int grid[n][n];
    int init = 0;
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < n/2; j++){
            grid[i][j] = 4*init + 1;
            grid[i][j+n/2] = 4*init + 2;
            grid[i+n/2][j] = 4*init + 3;
            grid[i+n/2][j+n/2] = 4*init;
            init++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] << " \n"[j == n-1];
        }
    }
    return 0;
}
