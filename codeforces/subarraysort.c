#include<stdio.h>
int main(){
    long long int t, k;
    scanf("%lld", &t);
    for(k = 0; k < t; k++){
        long long int n;
        scanf("%lld", &n);
        long long int i, j, a[n], b[n], count = 0;
        for(i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        for(j = 0; j < n; j++)
            scanf("%lld", &b[j]);
        if(a[0] != b[0] || a[n-1] != b[n-1])
            printf("NO\n");
        else{
            for(i = 1; i < n-2; i++){
                for(j = i+1; j < n-1; j++){
                    if(a[i] < a[j]){
                        int swap = a[i];
                        a[i] = a[j];
                        a[j] = swap;
                    }
                    if(b[i] < b[j]){
                        int swap = b[i];
                        b[i] = b[j];
                        b[j] = swap;
                    }
                }
            }        
            for(i = 0; i < n; i++){
                if(a[i] != b[i])
                    count = 1;
            }
            if(count == 1)
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
    return 0;
}
