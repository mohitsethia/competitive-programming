#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], one = 0, zero = 0, minus = 0, other = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] == 0) zero++;
            else if(a[i] == 1) one++;
            else if(a[i] == -1) minus++;
            else other++;
        }
        if(other > 1){
            cout << "no" << endl;
            continue;
        }
        bool ok = true;
        if(minus > 1){
            if(!one){
                ok = false;
            }
        }
        if(minus > 0){
            if(other){
                ok = false;
            }
        }
        cout << (ok ? "yes" : "no") << endl;
    }
    return 0;
}
