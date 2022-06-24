#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;
#define int long long
bool isTrue(vector<vector<int> >& a, vector<vector<int> >& b, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(a[i][j] != b[i][j]){
                return false;
            }
        }
    }
    return true;
}

void solve(){
    int r, c, x;
    cin >> r >> c >> x;
    vector<vector<int> > a(r, vector<int>(c, 0)), b(r, vector<int>(c, 0));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> b[i][j];
        }
    }
    if(r < x && c < x){
        if(isTrue(a, b, r, c)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        return;
    }
    else if(r < x){
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c-x+1; j++){
                if(a[i][j] != b[i][j]){
                    int d = b[i][j] - a[i][j];
                    a[i][j] += d;
                    int k = 1;
                    while(k < x){
                        a[i][j+k] += d;
                        k++;
                    }
                }
            }
        }
        if(isTrue(a, b, r, c)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        return;
    }
    else if(c < x){
        for(int i = 0; i < r-x+1; i++){
            for(int j = 0; j < c; j++){
                if(a[i][j] != b[i][j]){
                    int d = b[i][j] - a[i][j];
                    a[i][j] += d;
                    int k = 1;
                    while(k < x){
                        a[i+k][j] += d;
                        k++;
                    }
                }
            }
        }
        if(isTrue(a, b, r, c)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        return;
    }
    else{
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c-x+1; j++){
                if(a[i][j] != b[i][j]){
                    int d = b[i][j] - a[i][j];
                    a[i][j] += d;
                    int k = 1;
                    while(k < x){ 
                        a[i][j+k] += d;
                        k++;
                    }   
                }   
            }   
        }
        for(int i = 0; i < r-x+1; i++){
            for(int j = 0; j < c; j++){
                if(a[i][j] != b[i][j]){
                    int d = b[i][j] - a[i][j];
                    a[i][j] += d;
                    int k = 1;
                    while(k < x){ 
                        a[i+k][j] += d;
                        k++;
                    }   
                }   
            }   
        }      
        if(isTrue(a, b, r, c)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        return;
    }
}

int32_t main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
