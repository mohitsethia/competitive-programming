#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int m, n;
    cin >> m >> n;
    int b[m][n], a[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = 1;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> b[i][j];
            if(b[i][j] == 0){
                a[i][j] = 0;
                for(int k = 0; k < n; k++){
                    a[i][k] = 0;
                }
                for(int k = 0; k < m; k++){
                    a[k][j] = 0;
                }
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int temp = 0;
            for(int k = 0; k < m; k++){
                temp |= a[k][j];
            }
            for(int k = 0; k < n; k++){
                temp |= a[i][k];
            }
            if(temp != b[i][j]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
