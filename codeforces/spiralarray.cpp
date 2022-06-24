#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int startrow = 0, startcol = 0, endrow = n-1, endcol = m-1;
    while(startrow <= endrow and startcol <= endcol){
        for(int i = startrow; i <= endrow; i++){
            cout << a[i][startcol] << " ";
        }
        startcol++;
        for(int i = startcol; i <= endcol; i++){
            cout << a[endrow][i] << " ";
        }
        endrow--;
        if(endcol >= startcol){
            for(int i = endrow; i >= startrow; i--){
                cout << a[i][endcol] << " ";
            }
            endcol--;
        }
        if(endrow >= startrow){
            for(int i = endcol; i >= startcol; i--){
                cout << a[startrow][i] << " ";
            }
            startrow++;
        }
    }
    return 0;
}
