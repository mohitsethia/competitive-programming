#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N = int(3e5)+99;
const int INF = int(1e9)+99;
int n;
int st[4*N+55];
vector<int> p[N];
int a[N], b[N];
int getMin(int start, int end, int l, int r, int node){
    if(l >= r) return INF;
    if(start == l && end == r)
        return st[node];
    int mid = (start+end)/2;
    return min(getMin(start, mid, l, min(r, mid), 2*node+1), getMin(mid, end, max(mid, l), r, 2*node+2));
}
void update(int start, int end, int pos, int val, int node){
    if(end-start == 1){
        st[node] = val;
        return;
    }
    int mid = (start+end)/2;
    if(pos < mid){
        update(start, mid, pos, val, 2*node+1);
    }
    else{
        update(mid, end, pos, val, 2*node+2);
    }
    st[node] = min(st[2*node+1], st[2*node+2]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            p[i].clear();
        }
        for(int i = 0; i < n; i++){
            cin >> a[i];
            --a[i];
            p[a[i]].push_back(i);
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
            --b[i];
        }
        for(int i = 0; i < 4*n; i++){
            st[i] = INF;
        }
        for(int i = 0; i < n; i++){
            reverse(p[i].begin(), p[i].end());
            if(!p[i].empty()){
                update(0, n, i, p[i].back(), 0);
            }
        }
        bool ok = true;
        for(int i = 0; i < n; i++){
            if(p[b[i]].empty()){
                ok = false;
                break;
            }
            int pos = p[b[i]].back();
            if(getMin(0, n, 0, b[i], 0) < pos){
                ok = false;
                break;
            }
            p[b[i]].pop_back();
            update(0, n, b[i], p[b[i]].empty() ? INF : p[b[i]].back(), 0);
        }
        if(ok)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
