#include<stdio.h>
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		long long int L, R, count = 0;
		scanf("%lld%lld", &L, &R);
		for(int i = L; i <= R; i++)
			count++;
		if(count % 2 == 0)
			printf("Even\n");
		else
			printf("Odd\n");
	}
}