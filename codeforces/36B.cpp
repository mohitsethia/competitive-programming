#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

#define sz(a)       (int)a.size()

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<vector<char> > a(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    vector<vector<char> > res(1, vector<char>(1, '.'));
    for(int _ = 0; _ < k; _++){
        vector<vector<char> > now(res.size()*n, vector<char>(res.size()*n, '.'));
        for(int i = 0; i < sz(res); i++){
            for(int j = 0; j < sz(res); j++){
                if(res[i][j] == '*'){
                    for(int s = 0; s < n; s++){
                        for(int t = 0; t < n; t++){
                            now[i*n+s][j*n+t] = '*';
                        }
                    }
                }
                else{
                    for(int s = 0; s < n; s++){
                        for(int t = 0; t < n; t++){
                            now[i*n+s][j*n+t] = a[s][t];
                        }
                    }
                }
            }
        }
        res = now;
    }
    for(int i = 0; i < sz(res); i++){
        for(int j = 0; j < sz(res); j++){
            cout << res[i][j];
        }
        cout << "\n";
    }
    return 0;
}
