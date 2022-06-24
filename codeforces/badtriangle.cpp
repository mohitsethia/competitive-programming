#include<iostream>
#define int long long 
using namespace std;
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n+1];
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        bool flag = true;
        if(a[1] + a[2] <= a[n]){
            cout << "1 2 " << n << endl;
            flag = false;
        }
        else{
            cout << "-1" << endl;
        }
    }
    return 0;
}
