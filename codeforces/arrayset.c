#include<stdio.h>
int main(){
    int n, n3 = 0, a, i, l = 0, k = 0, j = 0, n1[1000], n2[1000];
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a);
        if(a == 0){
            l++;
        }
        else if(a > 0){
            n1[k] = a;
            k++;
        }
        else if(a < 0){
            n2[j] = a;
            j++;
        }
    }
    if(k == 0){
        n1[0] = n2[j-1];
        n1[1] = n2[j-2];
        j -= 2;
        k += 2;
    }
    if(j % 2 == 0){
        j--;
        n3 = n2[j];
        l++;
    }
    printf("%d ", j);
    for(i = 0; i < j; i++){
        printf("%d ", n2[i]);
    }
    printf("\n%d ", k);
    for(i = 0; i < k; i++){
        printf("%d ", n1[i]);
    }
    printf("\n%d ", l);
    if(n3 != 0){
        l--;
    }
    for(i = 0; i < l; i++){
        printf("0 ");
    }
    if(n3 != 0){
        printf(" %d", n3);
    }
    return 0;
}
