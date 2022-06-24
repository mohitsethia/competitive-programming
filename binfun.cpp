#include<iostream>
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
        for(int i = 0 ; i <n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        int x, y, diff = INT_MAX;
        for(int i = 0; i < n-1; i++){
            if(a[i+1] - a[i] < diff){
                diff = a[i+1] -a[i];
                x = a[i+1];
                y = a[i];
            }
        }
        int ans;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(abs(concat(a[i], a[j]) - concat(a[j], a[i])) > ans){
                    ans = abs(concat(a[i], a[j]) - concat(a[j], a[i]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
