#include<stdio.h>
int main(){
    int n, i, j;
    scanf("%d", &n);
    int a[n], b[n], count = 0, c1, c2, c3, c4;
    for(i = 0; i < n; i++){
        scanf("%d%d", &a[i], &b[i]);
    }
    for(i = 0; i < n; i++){
        c1 = c2 = c3 = c4 = 0;
        for(j = 0; j < n; j++){
            if(i != j && b[i] == b[j]){
                if(a[i] < a[j])
                    c1++;
                else if(a[i] > a[j])
                    c2++;
            }
            else if(i != j && a[i] == a[j]){
                if(b[i] > b[j])
                    c3++;
                else if(b[i] < b[j])
                    c4++;
            }
        }
        if(c1 >= 1 && c2 >= 1 && c3 >= 1 && c4 >= 1)
            count++;
    }
    printf("%d", count);
    return 0;
}
