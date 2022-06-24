#include<iostream>
#include<cstring>
using namespace std;

void recursion(char *s){
    if(s[0]=='\0'){
        return;
    }
    if(s[0]==s[1]){
        int i=0;
        while(s[i]!='\0'){
            s[i]=s[i+1];
            i++;
        }
       recursion(s); 
    }
    recursion(s+1);
}

int main() {
	char a[1000];
	cin>>a;
	recursion(a);
	for(int i=0;a[i]!='\0';i++)
	{
		cout<<a[i];
	}
	return 0;
}
