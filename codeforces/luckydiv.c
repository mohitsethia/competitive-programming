#include<stdio.h>
int main(){
    int n, count = 0, i;
    scanf("%d", &n);
    int a[] = {4, 7, 47, 74, 447, 477, 474, 744, 747, 774};
    for(i = 0; i < 10; i++){
        if(n % a[i] == 0)
            count++;
}
    if(count >= 1)
        printf("YES");
    else
        printf("NO");
   return 0;
}
