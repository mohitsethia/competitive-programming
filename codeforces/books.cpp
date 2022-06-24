#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
int32_t main(){
    int n, t;
    cin >> n >> t;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 0, l = 0, sum = 0;
    for(int r = 0; r < n; r++){
        sum += a[r];
        while(sum > t){
            sum -= a[l];
            l++;
        }
        ans = max(ans, r-l+1);
    }
    cout << ans << endl;
    return 0;
}
