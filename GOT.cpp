//spoj.com/problems/GOT/
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int BLK = 700;
const int H = 19;
const int N = 1e5 + 1;
vector<int> ar[N];
struct query{
    int l, r, idx, c, lca;
};
query Q[2*N];
int par[N][H+1], lvl[N];
int timer = 1;
int nodeF[N], eleF[N], val[N], res[2*N];
int S[N], T[N], ft[2*N];
void dfs(int z, int p){
    lvl[z] = lvl[p]+1;
    par[z][0] = p;
    S[z] = timer;
    ft[timer] = z;
    timer++;
    for(int i = 1; i <= H; i++){
        par[z][i] = par[par[z][i-1]][i-1];
    }
    for(auto it: ar[z]){
        if(it == p) continue;
        dfs(it, z);
    }
    T[z] = timer;
    ft[timer] = z;
    timer++;
}
/*
void init(int n){
    for(int j = 1; j < 20; j++){
        for(int i = 1; i <= n; i++){
            if(par[i][j-1] != -1){
                par[i][j] = par[par[i][j-1]][j-1];
            }
        }
    }
}
int getLCA(int a , int b)
{
	if(lvl[a] > lvl[b])
	swap(a , b);

	int d = lvl[b] - lvl[a];

	int f = 0;

	while(d)
	{
		if(d & 1)
		b = par[b][f];

		d >>= 1;
		f++;
	}

	if(a == b)
	return a;

	for(int j=20-1;j>=0;j--)
	if(par[a][j] != -1 && (par[a][j] != par[b][j]))
	a = par[a][j] , b = par[b][j];
	return par[a][0];
}
*/

int lca(int x, int y){
    if(lvl[x] < lvl[y]) swap(x, y);
    for(int i = H; i >= 0; i--){
        if(lvl[x] - (1 << i) >= lvl[y]){
            x = par[x][i];
        }
    }
    if(x == y) return x;
    for(int i = H; i >= 0; i--){
        if(par[x][i] != par[y][i]){
            x = par[x][i], y = par[y][i];
        }
    }
    //cout << par[x][0] << "\n";
    return par[x][0];
}

bool comp(query a, query b){
    int x = a.l/BLK;
    int y = b.l/BLK;
    if(x != y)
        return x < y;
    else 
        return a.r < b.r;
}

void add(int pos){
    int node = ft[pos];
    nodeF[node]++;
    if(nodeF[node] == 1){
        int c = val[node];
        eleF[c]++;
    }
    else{
        int c = val[node];
        eleF[c]--;
    }
}

void remove(int pos){
    int node = ft[pos];
    nodeF[node]--;
    if(nodeF[node] == 1){
        int c = val[node];
        eleF[c]++;
    }
    else{
        int c = val[node];
        eleF[c]--;
    }
}

int main(){
    int n, m;
    while(cin >> n >> m){
        for(int i = 0; i <= n; i++){
            ar[i].clear();
            eleF[i] = 0;
            nodeF[i] = 0;
        }
        for(int i = 0; i <= m; i++) res[i] = 0;
        for(int i = 1; i <= n; i++){
            cin >> val[i];
        }
        int a, b;
        for(int i = 1; i < n; i++){
            cin >> a >> b;
            ar[a].emplace_back(b);
            ar[b].emplace_back(a);
        }
        memset(par, -1, sizeof par);
        timer = 1;
        dfs(1, -1);
        //init(n);
        int c;
        for(int i = 1; i <= m; i++){
            cin >> a >> b >> c;
            if(S[a] > S[b]){
                swap(a, b);
            }
            int lp = lca(a, b);
            Q[i].idx = i;
            Q[i].c = c;
            if(a == lp){
                Q[i].l = S[a];
                Q[i].r = S[b];
                Q[i].lca = -1;
            }
            else{
                Q[i].l = T[a];
                Q[i].r = S[b];
                Q[i].lca = lp;
            }
        }
        sort(Q+1, Q+m+1, comp);
        int ML = 1, MR = 0;
        for(int i = 1; i <= m; i++){
            int L = Q[i].l;
            int R = Q[i].r;
            c = Q[i].c;
            int lca = Q[i].lca;
            while(MR < R) MR++, add(MR);
            while(ML > L) ML--, add(ML);

            while(MR > R) remove(MR), MR--;
            while(ML < L) remove(ML), ML++;
            
            if(eleF[c] > 0){
                res[Q[i].idx] = 1;
            }
            if(lca != -1 && val[lca] == c){
                res[Q[i].idx] = 1;
            }
        }
        for(int i = 1; i <= m; i++){
            if(res[i] == 1){
                cout << "Find\n";
            }
            else{
                cout << "NotFind\n";
            }
        }
        cout << endl;
    }
    return 0;
}
