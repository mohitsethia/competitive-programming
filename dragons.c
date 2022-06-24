#include<stdio.h>

int main(){
    int i, s, n, count = 0;
    scanf("%d%d", &s, &n);
    int x[n], y[n], swap1, swap2;
    for(i = 1; i <= n; i++)
        scanf("%d%d", &x[i], &y[i]);
    for(i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            if(x[i] > x[j]){
                swap1 = x[i];
                x[i] = x[j];
                x[j] = swap1;
                swap2 = y[i];
                y[i] = y[j];
                y[j] = swap2;
            }
        }
    }
    for(i = 1; i <= n; i++){
        if(s > x[i]){
            s += y[i];
            count++;
        }
    }
    if(count == n)
        printf("YES");
    else
        printf("NO");
    return 0;
}
