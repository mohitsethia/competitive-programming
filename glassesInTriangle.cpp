#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

const int N = 1e3;

double glasses[N][N];

void fillWineInGlasses(int n){
    glasses[0][0] = n;
    int level = 0;
    bool wineInLevel = true;
    while(wineInLevel){
        wineInLevel = false;
        for(int j = 0; j <= level; j++){
            if(glasses[level][j] > 1){
                double extraWine = glasses[level][j] - 1.0;
                glasses[level][j] = 1.0;
                glasses[level+1][j] += extraWine/2.0;
                glasses[level+1][j+1] += extraWine/2.0;
                wineInLevel = true;
            }
        }
        level++;
    }
}

int main(){
    int row, col;
    cin >> row >> col;
    double L;
    cin >> L;
    fillWineInGlasses(L);
    cout << glasses[row-1][col-1] << "\n";
    return 0;
}
