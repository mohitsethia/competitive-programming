#include <iostream>
#include <algorithm>

using namespace std;

#define trace(x) cerr << #x << " = [" << x.first.first << " " << x.first.second << " " << x.second << "]\n";

const int N=5005;

int n;
int w[N], h[N], len[N], vis[N], par[N];

void dfs(int idx)
{
    if(vis[idx])
        return;
    vis[idx]=1;
    for(int i=0;i<=n;i++)
    {
        if(w[idx]<w[i] && h[idx]<h[i])
        {
            dfs(i);
            if(len[i]+1>len[idx])
            {
                len[idx]=len[i]+1;
                par[idx]=i;
            }
        }
    }
}

void path(int idx)
{
    cout<<idx;
    if(par[idx])
    {
        cout<<" ";
        path(par[idx]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w[0] >> h[0];
	for(int i=1;i<=n;i++) {
		cin >> w[i] >> h[i];
    }
	dfs(0);
	cout << len[0] << endl;
	if(len[0]) {
		path(par[0]);
    }
    return 0;
}
