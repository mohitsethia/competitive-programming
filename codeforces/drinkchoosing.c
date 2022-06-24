#include<stdio.h>
int main(){
    int n, k, odd = 0, i, a, b[10000];
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &a),
        a--;
        b[a]++;
    }
    for(a = 0; a < k; a++){
        if(b[a] % 2 != 0)
            odd++;
    }
    printf("%d\n", n - (odd/2));
    return 0;
}
