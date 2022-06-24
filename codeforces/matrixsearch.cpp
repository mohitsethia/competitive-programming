#include<iostream>
using namespace std;
bool present(int n, int m, int a[][30], int target){
    int l = 0, r = 0;
    for(int i = 0; i < n; i++){
        if(a[i][0] < target){
            l = i;
        }
        if(a[i][0] == target){
            return true;
        }
    }
    for(int j = 0; j < m; j++){
        if(a[l][j] < target){
            r = j;
        }
        if(a[l][j] == target){
            return true;
        }
    }
    return false;
}
int main(){
    int n, m;
    cin >> n >> m;
    int a[30][30];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int target;
    cin >> target;
    if(present(n, m, a, target)){
        cout << "1";
    }
    else{
        cout << "0";
    }
    return 0;
}
