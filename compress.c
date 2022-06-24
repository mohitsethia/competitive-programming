#include<stdio.h>
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, i;
        scanf("%d", &n);
        int a[n], j;
        for(i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        for(i = 0; i < n; i++){
            int k = 1;
            for(j = i+1; j < n; j++){
                if(a[i] == (a[j] - k)){
                    k++;
                }
                else{
                    break;
                }
            }
            if(k > 2){
                printf("%d...%d", a[i], a[j-1]);
                i = j-1;
            }
            else{
                printf("%d", a[i]);
            }
            if(i < n-1){
                printf(",");
            }
        }
        printf("\n");
    }
    return 0;
}
