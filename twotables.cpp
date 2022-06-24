#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
    int na, ma;
    cin >> na >> ma;
    char a[na][ma];
    for(int i = 0; i < na; i++){
        for(int j = 0; j < ma; j++){
            cin >> a[i][j];
        }
    }
    int nb, mb;
    cin >> nb >> mb;
    char b[nb][mb];
    for(int i = 0; i < nb; i++){
        for(int j = 0; j < mb; j++){
            cin >> b[i][j];
        }
    }
    int ans = -1, c1, c2;
    for(int x = -50; x < 51; x++){
        for(int y = -50; y < 51; y++){
            int sum = 0;
            for(int i = 0; i < na; i++){
                for(int j = 0; j < ma; j++){
                    if(i+x >= 0 && i+x < nb && j+y >= 0 && j+y < mb){
                        int t1 = a[i][j];
                        int t2 = b[i+x][j+y];
                        sum += (t1-'0')*(t2-'0');
                    }
                }
            }
            if(sum > ans){
                ans = sum;
                c1 = x;
                c2 = y;
            }
        }
    }
    cout << c1 << " " << c2 << "\n";
    return 0;
}
