#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        char *n;
        n = (char*)malloc(sizeof(char)*51);
        long long int sum = 0, i;
        scanf("%s", n);
        for(i = 0; i < strlen(n); i++)
            sum += (n[i] - '0');
        printf("%lld\n", sum);
    }
	return 0;
}
