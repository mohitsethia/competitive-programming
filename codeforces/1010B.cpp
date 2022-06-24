#include<iostream>
#include<algorithm>

#define int long long
using namespace std;

bool ask(int x){
	cout<<x<<endl;
	fflush(stdout);
	int t;
	cin>>t;
	if(!t)exit(0);
	return t<0?0:1;
}
bool op[32];

signed main(){
	int m,n;
	cin>>m>>n;
	int l=1,r=m;
	for(int i=1;i<=n;i++)op[i]=ask(1);
	int mid,k=0;
	while(l<r){
		mid=(l+r)/2;
		if(ask(mid)^op[k%n+1])r=mid;
		else l=mid+1;
		k++;
	}
	ask(l);
}
