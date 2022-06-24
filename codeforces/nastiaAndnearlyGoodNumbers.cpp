#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(b == 1){
            cout << "NO" << endl;
        }
        else{
            int y = a*b;
            int z = a*(b+1);
            cout << "YES" << endl;
            cout << a << " " << y << " " << z << endl;
        }
    }
    return 0;
}
