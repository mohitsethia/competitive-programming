#include <iostream>
#include <algorithm>

using namespace std;
 
const int N=1e6+5;

int n;
int a[N], b[N], c[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n/2;i++)
    {
        cin>>a[i];
        b[i]=2*(i-1) + 1;
        c[i]=2*i;
    }
    sort(a+1, a+n/2+1);
    int ans1=0, ans2=0;
    for(int i=1;i<=n/2;i++)
    {
        ans1+=abs(a[i]-b[i]);
        ans2+=abs(a[i]-c[i]);
    }
    cout<<min(ans1, ans2);
    return 0;
}
