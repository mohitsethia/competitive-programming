#include<stdio.h>
int main(){
    int n, m;
    printf("Enter the size of array A and B respectively: ");
    scanf("%d%d", &n, &m);
    int a[n], b[m];
    int check = 0;
    int freqa[100005] = {0};
    int freqb[100005] = {0};
    printf("Enter the elements of array A: "); 
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        freqa[a[i]]++;
    }
    printf("Enter the elements of array B: ");
    for(int i = 0; i < m; i++){
        scanf("%d", &b[i]);
        if(!freqa[b[i]]){
            check = 1;
        }
        freqb[b[i]]++;
    }
    for(int i = 0; i < n; i++){
        if(!freqb[a[i]]){
            check = 1;
        }
    }
    if(check == 1){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
    return 0;
}
