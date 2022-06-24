/*
#include<stdio.h> 

// function to find double factorial of given number 
unsigned int doublefactorial(unsigned int n) 
{ 
	if (n == 0 || n==1) 
	return 1; 
	return n*doublefactorial(n-2); 
} 

int main() 
{ 
    int x;
    scanf("%d", &x);
    long long int z = doublefactorial(x);
    printf("%lld %lld", z, z % 456);
	return 0; 
} 
*/
#include<stdio.h> 

// function to find double factorial of given number 
unsigned int doublefactorial(unsigned int n) 
{ 
	int res = 1; 
	for (int i=n; i>=0; i=i-2) 
	{ 
		if (i==0 || i==1) 
			return res; 
		else
			res *= i; 
	}
    
} 

int main() 
{ 
	printf("Double factorial is %d", doublefactorial(123) % 456); 
	return 0; 
} 

