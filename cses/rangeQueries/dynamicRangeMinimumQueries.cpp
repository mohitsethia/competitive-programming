#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<climits>
using namespace std;
#define int long long
#define INF INT_MAX
vector<int> tree;
int query(int node, int start, int end, int l, int r){
    if(end < l || start > r){
        return INF;
    }
    if(start >= l && r >= end){
        return tree[node];
    }
    int mid = (start+end)/2;
    int left = query(2*node, start, mid, l, r);
    int right = query(2*node+1, mid+1, end, l, r);
    return min(left, right);
}
void update(int start, int end, int val, int idx, int node){
    if(start > idx || end < idx){
        return;
    }
    if(start == idx && end == idx){
        tree[node] = val;
        return;
    }
    int mid = (start+end)/2;
    update(start, mid, val, idx, 2*node);
    update(mid+1, end, val, idx, 2*node+1);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int& i: a){
        cin >> i;
    }
    while(__builtin_popcount(n) != 1){
        n++;
    }
    tree.resize(2*n);
    for(int i = 0; i < (int)a.size(); i++){
        tree[n+i] = a[i];
    }
    for(int i = n-1; i >= 1; i--){
        tree[i] = min(tree[2*i], tree[2*i+1]);
    }
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int idx, val;
            cin >> idx >> val;
            idx--;
            update(0, n-1, val, idx, 1);
        }
        else{
            int l, r;
            cin >> l >> r;
            --l, --r;
            cout << query(1, 0, n-1, l, r) << endl;
        }
    }
    return 0;
}
