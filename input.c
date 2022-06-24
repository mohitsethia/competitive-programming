#include<stdio.h>
int n, k, count;
long long int t;
int main(){
	scanf("%d%d", &n, &k);
	while(n--){
	scanf("%lld", &t);
	if(t % k == 0)
	count++;
	}
	printf("%d", count);
}