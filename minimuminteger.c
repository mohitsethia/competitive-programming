#include<stdio.h>
int main(){
	int q;
	scanf("%d", &q);
	while(q--){
	long long int l, r, d, a[1000000000], smallest = 0;
	scanf("%lld%lld%lld", &l, &r, &d);
	smallest = a[0];
	for(int i = 0; i < 1000000000; i++){
		if((a[i] < smallest) && (i % d == 0) && ((i < l) || (i > r))){
			smallest = a[i];
		}
	}
		printf("%lld", smallest);
	}
	return 0;
}