#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    int a[n+1];
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 1){
            cnt++;
        }
    }
    while(q--){
        int t, x;
        cin >> t >> x;
        if(t == 1){
            if(a[x] == 1){
                a[x] = 0;
                cnt--;
            }
            else{
                a[x] = 1;
                cnt++;
            }
        }
        else{
            if(x <= cnt){
                cout << "1\n";
            }   
            else{
                cout << "0\n";
            }
        }
    }
    return 0;
}
