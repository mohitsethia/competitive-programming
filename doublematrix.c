#include<stdio.h>
int main(){
    int n, m;
    const int s = 50;
    int a[s][s];
    int b[s][s];
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &b[i][j]);
            if(a[i][j] > b[i][j]){
                int swap = b[i][j];
                    b[i][j] = a[i][j];
                    a[i][j] = swap;
            }
        }
    }
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            if(b[i][j] >= b[i+1][j] || a[i][j] >= a[i+1][j]){
                printf("Impossible");
                return 0;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m-1; j++){
            if(b[i][j] >= b[i][j + 1] || a[i][j] >= a[i][j+1]){
                printf("Impossible");
                return 0;
            }
        }
    }
    printf("Possible");
    return 0;
}
