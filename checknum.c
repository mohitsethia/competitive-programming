#include<stdio.h>
int main(){
	long long int T, n;
	scanf("%lld", &T);
	while(T--){
		scanf("%lld", &n);
		if(n < 0)
			printf("%lld is negative number\n", n);
		else if(n > 0)
			printf("%lld is positive number\n", n);
		else
			printf("n is zero\n");
	}
}