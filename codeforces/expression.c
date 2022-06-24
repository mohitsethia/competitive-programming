#include<stdio.h>
int main(){
    int i, a, b, c, arr[6];
    scanf("%d%d%d", &a, &b, &c);
    arr[0] = a + b * c;
    arr[1] = a * b * c;
    arr[2] = a * (b + c);
    arr[3] = (a + b) * c;
    arr[4] = a + b + c;
    arr[5] = a * b + c;
    int max = arr[0];
    for(i = 0; i < 6; i++){
        if(max < arr[i])
            max = arr[i];
}
    printf("%d", max);
    return 0;
}
