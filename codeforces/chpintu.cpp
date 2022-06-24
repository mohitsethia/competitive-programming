#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> n >> m;
        int f[n], p[n], i, sum1 = 0, sum2 = 0;
        for(i = 0; i < n; i++){
            cin >> f[i];
        }
        for(i = 0; i < n; i++){
            cin >> p[i];
            if(f[i] == f[0]){
                sum1 += p[i];
            }
        }
        for(i = 0; i < n; i++){
            sum2 = 0;
            for(int j = 0; j < n; j++){
                if(f[i] == f[j]){
                    sum2 += p[j];
                }
            }
            if(sum2 < sum1){
                sum1 = sum2;
            }
        }
        printf("%d\n", sum1);
    }
    return 0;
}
