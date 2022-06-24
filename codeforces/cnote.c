#include<stdio.h>
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		long int X, Y, K, N, i, s = 0;
		scanf("%ld%ld%ld%ld", &X, &Y, &K, &N);
			long int P[N], C[N];
			for(i = 1; i <= N; i++){
				scanf("%ld%ld", &P[i], &C[i]);
				if((P[i] >= (X-Y)) && (C[i] <= K))
					s = 1;
			}
			if(s == 1)
				printf("LuckyChef\n");
			else
				printf("UnluckyChef\n");
	}
}