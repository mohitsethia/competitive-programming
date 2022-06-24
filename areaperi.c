#include<stdio.h>
int main(){
	int L, B, Area, Peri;
	scanf("%d%d", &L, &B);
	Area = L * B;
	Peri = 2 * (L + B);
	if(Area > Peri)
		{
			printf("Area");
			printf("\n%d", Area);
		}
		else if(Peri > Area)
		{
			printf("Peri");
			printf("\n%d", Peri);
		}
		else
		{
			printf("Eq");
			printf("\n%d", Area);
		}
}

