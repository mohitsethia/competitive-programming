#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        if(k == n*m-1)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
