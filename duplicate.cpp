#include<iostream>
#include <cstring>
using namespace std;

void f(char * a,int t)
{
if(t==strlen(a)) return ;

if(a[t]==a[t+1])
{
	for(int i=strlen(a);i>t;i--)
		a[i]=a[i-1];
	
	a[t+1]='*';
}

f(a,t+1);

return ;
}


int main()
{
char a[2000];
cin>>a;
f(a,0);
cout<<a;
return 0;
}

