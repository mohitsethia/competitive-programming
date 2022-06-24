#include<stdio.h>
int main(){
    int n, i;
    scanf("%d", &n);
    int a[n], j;
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

/*
    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
            if(a[i] < a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    if(a[0] == a[n/2])
        printf("Bob");
    else
        printf("Alice");
    return 0;
}
*/
    int count = 0;
    j = a[0];
    for(i = 0; i < n; i++){
        if(a[i] < j)
            j = a[i];
    }
    for(i = 0; i < n; i++){
        if(a[i] == j)
            count++;
    }
    if(count <= (n/2))
        printf("Alice");
    else
        printf("Bob");
    return 0;
}
