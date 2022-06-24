#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int a[n], i, flag = 0, count = 0, j;
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int min = a[0], max = a[0];
    for(i = 0; i < n; i++){
        if(a[i] > max){
            max = a[i];
            count = i;
}
        if(a[i] <= min){
            min = a[i];
            flag = i;
}
}
    if(count > flag){
        flag = (n - 1) - flag;
        printf("%d\n", count + flag - 1);
}
    else{
        flag = (n-1) - flag;
        printf("%d", count + flag);    
}
    return 0;
}
