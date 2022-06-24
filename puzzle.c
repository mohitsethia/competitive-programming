#include<stdio.h>

int main(){
    int i, n, m;
    scanf("%d%d", &n, &m);
    int a[m];
    for(i = 0; i < m; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < m - 1; i++){
        for(int j = 0; j < m; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
        }
    }
}
    int min = a[n-1] - a[0];
    for(i = 1; i <= m-n; i++){
        if(a[i + n - 1] - a[i] < min)
            min = a[i + n - 1] - a[i];
}    
    printf("%d", min);
    return 0;
}
