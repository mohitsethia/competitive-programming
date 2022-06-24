#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<char> > mat(n, vector<char>(n, 0));
        int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
                if(mat[i][j] == '*'){
                    if(x1 == -1){
                        x1 = i;
                        y1 = j;
                    }
                    else{
                        x2 = i;
                        y2 = j;
                    }
                }
            }
        }
        if(x1 == x2){
            if(x1 + 1 != n){
                mat[x1+1][y1] = '*';
                mat[x2+1][y2] = '*';
            }
            else{
                mat[x1-1][y1] = '*';
                mat[x2-1][y2] = '*';
            }
        }
        else if(y1 == y2){
            if(y1+1 != n){
                mat[x1][y1+1] = '*';
                mat[x2][y2+1] = '*';
            }
            else{
                mat[x1][y1-1] = '*';
                mat[x2][y2-1] = '*';
            }
        }
        else{
            mat[x1][y2] = '*';
            mat[x2][y1] = '*';
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << mat[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
