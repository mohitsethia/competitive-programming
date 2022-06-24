#include<stdio.h>
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int i, j, arr[n];
    char a[n][m];
    for(i = 0; i < n; i++){
            scanf("%s", a[i]);
        arr[i] = 0;
    }
    int sum = 0;
    char max;
    for(j = 0; j < m; j++){
        max = a[0][j];
        for(i = 0; i < n; i++){
            if(max < a[i][j]){
                max = a[i][j];
            }
        }
        for(i = 0; i < n; i++){
            if(max == a[i][j])
                arr[i] = 1;
        }
    }
    for(i = 0; i < n; i++){
        sum += arr[i];
    }
    printf("%d\n", sum);
    return 0;
}
