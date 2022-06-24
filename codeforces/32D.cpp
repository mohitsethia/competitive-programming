#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    char a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> a[i][j];
    for(int r = 1; r <= 200; r++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == '.') continue;
                if(i-r >= 0 && i+r < n && j-r >= 0 && j+r < m){
                    if(a[i-r][j] == '*' && a[i+r][j] == '*' && a[i][j+r] == '*' && a[i][j-r] == '*'){
                        k--;
                        if(!k){
                            cout << i+1 << " " << j+1 << "\n";
                            cout << i-r+1 << " " << j+1 << "\n";
                            cout << i+r+1 << " " << j+1 << "\n";
                            cout << i+1 << " " << j-r+1 << "\n";
                            cout << i+1 << " " << j+r+1 << "\n";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "-1\n";
    return 0;
}
