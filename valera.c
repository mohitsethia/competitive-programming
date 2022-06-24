#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    char a[n][n];
    int i, j;
    for(i = 0; i < n; i++)
        scanf("%s", a[i]);
    char x = a[0][0], y = a[0][1];
    if(x == y){
        printf("NO\n");
        return 0;
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i != j && i != n-j-1){
                if(a[i][j] == y)
                    continue;
                else{
                    printf("NO\n");
                    return 0;
                }
            }
            else{
                if(a[i][j] == x)
                    continue;
                else{
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }
    printf("YES\n");
    return 0;
}


/*


#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    char a[n][n];
    int i, j, count1 = 0, count2 = 0;
    for(i = 0; i < n; i++)
            scanf("%s", a[i]);
    if(a[0][0] == a[0][1]){
        printf("NO\n");
        return 0;
    }
    else{
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(a[i][j] == a[0][0])
                    count1++;
                else if(a[i][j] == a[0][1])
                    count2++;
                if(a[i][j] != a[i][n-j-1]){
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }
    int m = 2*n -1;
    if(count1 == m && count2 == (n*n)-m)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

*/
