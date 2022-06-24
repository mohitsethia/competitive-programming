#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define int long long
int32_t main(){
    int n;
    cin >> n;
    int a[n], s = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    int num1 = s/3;
    int num2 = 2*num1;
    int ans = 0, c = 0, sum = 0;
    if(s%3 == 0){
        for(int i = 0; i < n-1; i++){
            sum += a[i];
            if(sum == num2){
                ans += c;
            }
            if(sum == num1){
                c++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
