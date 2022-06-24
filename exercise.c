#include<stdio.h>
#include<stdlib.h>
int** f(int m, int n, int **a){
    int i, j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++)
            a[i][j]++;
    }
    return a;
}

int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    int **a, i, j;
    a = (int **)malloc(m*sizeof(int *)); 
    for(i = 0; i < m; i++){
        a[i] = (int *)malloc(n*sizeof(int));
        for(j = 0; j < n; j++) {  
            scanf("%d", &a[i][j]);
        }
    }
        f(m, n, a);
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

/*
int f(int *n){
    printf("%d\n", *n);
    *n = *n+1;
    printf("%d\n", *n);
    return *n;
}
*/

