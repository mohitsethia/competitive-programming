#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int a[n], i, j, ch = 0, bi = 0, ba = 0;
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < 3; i++){
        for(j = i; j < n; j += 3){
            if(i == 0)
                ch += a[j];
            else if(i == 1)
                bi += a[j];
            else if(i == 2)
                ba += a[j];
        }
    }
    if(ch > bi){
        if(ch > ba)
            printf("chest\n");
        else
            printf("back\n");
    }
    else{
        if(bi > ba)
            printf("biceps\n");
        else
            printf("back\n");
    }
    return 0;
}
