#include<stdio.h>

void rearrange(int arr[], int n, int d){
    int i, j, k, l, x, y, m;
    m = n/d;
    if(m % 2 == 0){
    for(k = 1; k <= m/2; k++){
        x = (k - 1) * d;
        for(j = x; j < x + d; j++){
            printf("%d\n", arr[j]);
}
        y = n - ((k - 1) * d) - 1;
        for(l = y; l > y - d; l--){
            printf("%d\n", arr[l]);
}
}
}
    else{
        for(k = 1; k <= (m/2)+1; k++){
            x = (k - 1) * d;
            for(j = x; j < x + d; j++){
                if(j < n/2 + d)
                    printf("%d\n", arr[j]);
                else 
                    break;
}
                if(k == (m/2) +1)
                    break;
            y = n - ((k - 1) * d) - 1;
            for(l = y;l > y - d; l--)
                printf("%d\n", arr[l]);
}
}
}
int main(){
    int n, d;
    scanf("%d%d", &n, &d);
    int arr[n], i;
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
}
    rearrange(arr, n, d);
    return 0;
}
