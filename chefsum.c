#include <stdio.h>

int main() {
    int T, n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        int a[n], i, min, posi = 0;
        for(i = 0; i < n; i++){
            scanf("%d", &a[i]);
		min = a[0];
        }
        for(i = 1; i < n; i++){
            if(a[i] < min){
                min = a[i];
                posi = i;
            }
        }
        printf("%d\n", posi+1);
    }
	return 0;
}
