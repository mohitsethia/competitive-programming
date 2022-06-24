#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[n], i, count1 = 0, count2 = 0, index1, index2;
    for(i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(a[i] % 2 == 0){
            count1++;
            index1 = i;
        }
        else{
            count2++;
            index2 = i;
        }
    }
    if(count1 == 1)
        printf("%d", index1);
    else if(count2 == 1)
        printf("%d", index2);
    return 0;
}
