#include<stdio.h>
int main(){
int t;
scanf("%d", &t);
while(t--){
	int n, c;
	scanf("%d%d", &n, &c);
	int i;
	int s = 0;
	for(i = 0; i < n; i++){
		int a[i];
		scanf("%d", &a[i]);
		s = s + a[i];
	}
	if(c >= s)
		printf("Yes\n");
	else
		printf("No\n");
}
}
