#include<stdio.h>
#include<string.h>
int main(){
    int n, i;
    char a[1000000], b[1000000];
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        int l1 = 0, l2 = 0, j, k = 0, c = 0;
        scanf("%s%s", a, b);
        int m = strcmp(a, b);
        if(m == 0){
            printf("YES\n");
            continue;
        }   
        l1 = strlen(a);
        l2 = strlen(b);
        if(l1 > l2){
            printf("NO\n");
            continue;
        }
        if(a[0] != b[0] || a[l1 - 1] != b[l2 - 1]){
            printf("NO\n");
            continue;
        }
        for(j = 1; j < l2; j++){
            if(b[j] == a[k] || b[j] == a[k+1]){
                if(b[j] == a[k+1])
                    k++;
            }
            else{
                printf("NO\n");
                c = 1;
                break;
            }
        }
        if(c == 1)
            continue;
        if(k != l1 -1){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }
    return 0;
}
