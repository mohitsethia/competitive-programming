#include<stdio.h>
int max(int a[], int x){
    int i, max = a[0];
    for(i = 1; i < x; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    return max;
}
int min(int a[], int x){
    int i, min = a[0];
    for(i = 1; i < x; i++){
        if(a[i] < min){
            min = a[i];
        }
    }
    return min;
}
int main(){
    int n, m, i, j;
    scanf("%d%d", &n, &m);
    int a[n], b[m], x, y, z, p;
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(j = 0; j < m; j++){
        scanf("%d", &b[j]);
    }
    x = max(a, n);
    y = min(a, n);
    z = min(b, m);
    p = (2*y) > x ? (2*y) : x;
    if(p < z){
        printf("%d\n", p);
    }
    else{
        printf("-1\n");
    }
    return 0;
}
