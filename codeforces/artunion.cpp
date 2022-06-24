#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int m, n;
    cin >> m >> n;
    int paintingTime[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> paintingTime[i][j];
        }
    }
    vector<int> finishTime(m);
    for(int i = 0; i < n; i++){
        int freeAt = 0;
        for(int j = 0; j < m; j++){
            int start = max(freeAt, finishTime[j]);
            finishTime[j] = start + paintingTime[j][i];
            freeAt = finishTime[j];
        }
    }
    for(int i: finishTime){
        cout << i << " ";
    }
    return 0;
}
