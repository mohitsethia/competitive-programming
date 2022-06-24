#include<iostream>
#include<algorithm>

#define int long long
using namespace std;

signed main(){
    int n;
    scanf("%lld", &n);
    printf("2\n");
    for(int i = 2; i <= n; i++){
        int z = i*(i+1)*(i+1) - (i-1);
        printf("%lld\n", z);
    }
    return 0;
}
