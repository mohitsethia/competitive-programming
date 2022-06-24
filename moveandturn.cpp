#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n, dots = 1, times = 0, ans = 0;
    cin >> n;
    if(n%2 != 0){
        for(int i = 1; i <= n; i += 2){
            dots++;
            times++;
        }
        ans = 2*dots*times;
    }
    else{
        times = 1;
        for(int j = 2; j <= n; j += 2){
            dots++;
            times++;
        }
        ans = dots*times;
    }
    cout << ans << '\n';
    return 0;
}
