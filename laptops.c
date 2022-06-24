#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int i, a, b, count = 0;
    for(i = 0; i < n; i++){
        scanf("%d%d", &a, &b);
        if(a > b)
            count++;
    }
    if(count >= 1)
        printf("Happy Alex\n");
    else
        printf("Poor Alex\n");
    return 0;
}
