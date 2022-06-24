#include<stdio.h>
#include<math.h>
unsigned int factorial(unsigned int n){
	long long int res = 1, i;
	for(i = 2; i <= n; i++)
	res *= i;
	return res;
}
int main(){
	int num, T;
	scanf("%d", &T);
	while(T--){
	scanf("%d", &num);
    printf("%G\n", tgamma(num+1));
//	printf("%d\n", factorial(num));
	}
}
