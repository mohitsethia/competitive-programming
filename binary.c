#include<stdio.h>
#include<math.h>
int main(){
    int n, i;
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int mid, l = 0, u = n-1, s, floor = -1, ceil = -1;
    scanf("%d", &s);
    while(l <= u){
        mid = (l+u)/2;
        if(a[mid] == s){
            if(mid == 0){
                printf("-1 %d", a[mid+1]);
            }
            else
                printf("%d %d", a[mid-1], a[mid+1]);
            return 0;
        }
        else if(s < a[mid]){
            ceil = a[mid];
            u = mid - 1;
        }
        else{
            floor = a[mid];
            l = mid + 1;
        }
    }
    if(ceil == 1){
        printf("-1 %d", ceil);
    }
    else
        printf("%d %d", floor, ceil);
    return 0;
}
