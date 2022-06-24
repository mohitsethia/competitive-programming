#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int32_t main(){
    int t = 0;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        int i = 0, tot = 0;
        while(i < n && 2*a[i] < x){
            i++;
            tot++;
        }
        while(i < n){
            tot++;
            if(x < a[i] && 2*(a[i]-x) >= a[i]){
                x = 2*x;
                continue;
            }
            if(a[i] <= x){
                x = a[i];
                i++;
            }
            x = 2*x;
        }
        cout << tot << endl;
    }
    return 0;
}
