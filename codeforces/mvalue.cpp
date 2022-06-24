#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;  
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(n == 2){
            cout << a[0]*a[1] + abs(a[1]-a[0]) << endl;
            continue;
        }
        sort(a, a+n);
        if(-a[0] >= a[n-1] and -a[1] >= a[n-2]){
            a[n-1] = a[0];
            a[n-2] = a[1];
        }
        cout << a[n-1]*a[n-2] + abs(a[n-1]-a[n-2]) << endl;
    }
    return 0;
}
