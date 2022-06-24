#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
    int d, n;
    cin >> d >> n;
    int ans = 0, arr;
    for(int i = 0; i < n; i++){
        cin >> arr;
        if(i != n-1){
            ans += (d-arr);
        }
    }
    printf("%d\n", ans);
    return 0;
}
