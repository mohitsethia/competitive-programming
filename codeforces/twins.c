#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[n], i, j;
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
}
    int x;
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                x = a[i];
                a[i] = a[j];
                a[j] = x;
}
}
}
    int sum = 0, sum2 = 0, count = 1, half;
    for(i = 0; i < n; i++){
        sum += a[i];
}
    half = sum / 2;
    for(i = n - 1; i >= 0; i--){
        sum2 += a[i];
        if(sum2 > half){
            break;
}
            count++;
}
printf("%d", count);
    return 0;
}
