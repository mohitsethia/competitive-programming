#include<stdio.h>
void print(int arr[], int x, int y, int d, int type){
    if(x > y)
    return;
    if(type == 1){
        for(int i = x; i < x + d; i++)
            printf("%d\n", arr[i]);
        print(arr, x + d, y, d, 2);
}
    else{
        for(int i = y; i > y - d; i--)
            printf("%d\n", arr[i]);
        print(arr, x, y - d, d, 1);
}
}

int main(){
    int n, d;
    scanf("%d%d", &n, &d);
    int arr[n], i;
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
        print(arr, 0, n - 1, d, 1);
return 0;
}
