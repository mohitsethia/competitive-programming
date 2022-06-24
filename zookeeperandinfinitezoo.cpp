#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define int long long
int32_t main(){
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        if(a > b){
            cout << "NO\n";
            continue;
        }
        if(a == b){
            cout << "YES\n";
            continue;
        }
        int a1 = 0, b1 = 0, flag = 0;
        while(b){
            a1 += a&1;
            b1 += b&1;
            a /= 2;
            b /= 2;
            if(a1 < b1){
                flag = 1;
                break;
            }
        }
        if(!flag){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
