#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    if(n > m+1 || m > 2*(n+1)){
        cout << "-1" << endl;
        return 0;
    }
    if(n == m+1 || n == m){
        for(int i = 0; i < n+m; i++){
            if(i%2) cout << 1;
            else cout << 0;
        }
        return 0;
    }
    if(n == m){
        for(int i = 0; i < n+m; i++){
            if(i%2) cout << 1;
            else cout << 0;
        }
        return 0;
    }
    int cnt = m-n-1, f = 1;
    for(int i = 0; i < n+m; i++){
        if(f){
            cout << 1;
            if(cnt){
                cout << 1;
                cnt--;
                i++;
            }
            f = 0;
        }
        else{
            cout << 0;
            f = 1;
        }
    }
    return 0;
}
