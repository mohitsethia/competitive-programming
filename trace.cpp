#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
int32_t main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(i%2 == 0){
            ans += a[i]*a[i];
        }
        else{
            ans -= a[i]*a[i];
        }
    }
    ans = abs(ans);
    printf("%.10f", ans*3.1415926536);
    return 0;
}
