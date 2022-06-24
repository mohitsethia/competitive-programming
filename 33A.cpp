#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

const int N=1e3+5;

int n, m, k;
int a[N];

int32_t main()
{
    cin>>n>>m>>k;
    fill(a+1, a+N, k);
    for(int i=1;i<=n;i++)
    {
        int r, c;
        cin>>r>>c;
        a[r]=min(a[r], c);
    }
    int ans=0;
    for(int i=1;i<=m;i++)
        ans+=a[i];
    ans=min(ans, k);
    cout<<ans;
    return 0;
}
