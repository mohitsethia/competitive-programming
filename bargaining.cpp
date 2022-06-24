#include<iostream>
#include<algorithm>
using namespace std;
bool tab[30][30];
bool isAvailable(int a, int b, int c, int d){
    for(int i = a; i <= c; i++){
        for(int j = b; j <= d; j++){
            if(tab[i][j]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int n, m;
    string s;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            tab[i][j] = (s[j] == '1');
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = i; k < n; k++){
                for(int l = j; l < m; l++){
                    if(isAvailable(i, j, k, l)){
                        res = max(res, k-i+1+l-j+1);
                    }
                }
            }
        }
    }
    cout << res*2 << endl;
    return 0;
}
