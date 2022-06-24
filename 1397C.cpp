#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << "1 1\n0\n1 1\n0\n1 1\n" << -a[0] << "\n";
    }
    else{
        printf("1 %lld\n", n-1);
        for(int i = 0; i < n-1; i++){
            int add = (n-1)*a[i];
            printf("%lld ", add);
            a[i] += add;
        }
        printf("\n");
        printf("1 %lld\n", n);
        for(int i = 0; i < n-1; i++){
            printf("%lld ", -a[i]);
        }
        printf("0 \n");
        printf("%lld %lld\n", n, n);
        printf("%lld\n", -a[n-1]);
    }
    return 0;
}
