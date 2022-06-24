#include<stdio.h>
#include<string.h>
int main(){
    int n, k, i, j, l, sum = 0;
    scanf("%d%d", &n, &k);
    char a[n];
    scanf("%s", a);
    int l1 = strlen(a);
    int max = 0, c, m;
    for(i = 0; i < l1; i++){
        max = i+1;
        for(j = l1-1; j > i; j++){
            if(a[i] == a[j]){
                if(max >= sum){
                    max += (j+1);
                    c++;
                    l = i;
                }
            }
        }
        sum = max;
    }
    if(c > k){
        m = c - k;
        for(i = 0; i < l1; i++){
            if(m != 0){
                sum -= (i+1);
                m--;
            }
        }
    }
    else{
        m = k - c;
        sum += m;
    }
    printf("%d", sum);
    return 0;
}
