/*
#include<stdio.h>
int main(){
    int n, i, count = 0;
    scanf("%d", &n);
    int a[n], temp;
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int k = 0; k < n - 1; k++) {
        // (n-k-1) is for ignoring comparisons of elements which have already been compared in earlier iterations

        for(int i = 0; i < n-k-1; i++) {
            if(a[i] > a[i+1]) {
                count++;
                // here swapping of positions is being done.
                temp = a[ i ];
                a[ i ] = a[ i+1 ];
                a[ i + 1] = temp;
            }
        }
    }
            printf("%d", count);
}
*/

int bubble_sort( int A[ ], int n ) {
    int temp;
    for(int k = 0; k< n-1; k++) {
        // (n-k-1) is for ignoring comparisons of elements which have already been compared in earlier iterations

        for(int i = 0; i < n-k-1; i++) {
            if(A[ i ] > A[ i+1] ) {
                // here swapping of positions is being done.
                temp = A[ i ];
                A[ i ] = A[ i+1 ];
                A[ i + 1] = temp;
            }
        }
    }
}
#include<stdio.h>
int main(){
    int n, m, i, T;
    
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
            int a[n], c, sum1= 0, sum2 = 0, j;
                c = n -m;
                for(i = 0; i < n; i++)
                    scanf("%d", &a[i]);
                bubble_sort(a, a + n);
                i = 0, j = n-1;
                while(c--){
                    sum1 += a[i];
                        i++;
                    sum2 += a[j];
                        j--;
            }
                printf("%d\n", sum2 - sum1);
    }
}
