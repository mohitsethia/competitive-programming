#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<climits>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int a[n+1];
    memset(a, 0, sizeof(a));
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        if(!a[x] && !a[y] && !a[z]){
            a[x] = 1;
            a[y] = 2;
            a[z] = 3;
        }
        else if(a[x]){
            if(a[x] == 1){
                a[y] = 2;
                a[z] = 3;
            }
            else if(a[x] == 2){
                a[y] = 1;
                a[z] = 3;
            }
            else{
                a[y] = 1;
                a[z] = 2;
            }
        }
        else if(a[y]){
            if(a[y] == 1){
                a[x] = 2;
                a[z] = 3;
            }
            else if(a[y] == 2){
                a[x] = 1;
                a[z] = 3;
            }
            else{
                a[x] = 1;
                a[z] = 2;
            }
        }
        else{
            if(a[z] == 1){
                a[x] = 2;
                a[y] = 3;
            }
            else if(a[z] == 2){
                a[x] = 1;
                a[y] = 3;
            }
            else{
                a[x] = 1;
                a[y] = 2;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
