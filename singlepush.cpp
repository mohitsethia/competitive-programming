#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n, i;
        cin >> n;
        int a[n], b[n], flag = 1, k = 0;
        for(i = 0; i < n; i++){
            cin >> a[i];
        }
        for(i = 0; i < n; i++){
            cin >> b[i];
        }
        for(i = 0; i < n; i++){
            if(flag == 1){
                if(a[i] != b[i]){
                    k = a[i] - b[i];
                    flag = 0;
                    if(k > 0){
                        printf("NO\n");
                        break;
                    }
                }
            }
            else if(flag == 0){
                if(a[i] == b[i])
                    flag = 2;
                else if(a[i] - b[i] != k){
                    printf("NO\n");
                    break;
                }
            }
            else{
                if(a[i] != b[i]){
                    printf("NO\n");
                    break;
                }
            }
        }
        if(i == n){
            printf("YES\n");
        }
    }
    return 0;
}
