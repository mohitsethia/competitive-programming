#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
vector<int> tree;
int query(int start, int end, int l, int r, int node){
    if(start > r || end < l){
        return 0;
    }
    if(start >= l && r >= end){
        return tree[node];
    }
    int mid = (start+end)/2;
    int left = query(start, mid, l, r, 2*node);
    int right = query(mid+1, end, l, r, 2*node+1);
    return left+right;
}
void update(int i, int v, int n){
    tree[n+i] = v;
    for(int j = (n+i)/2; j >= 1; j /= 2){
        tree[j] = tree[2*j] + tree[2*j + 1];
    }
}
void change(int start, int end, int l, int r, int node, int v){
    if(l <= start && r >= end){
        tree[node] = v;
        return;
    }
    if(start > r || l > end){
        return;
    }
    int mid = (start+end)/2;
    change(start, mid, l, r, 2*node, v);
    change(mid+1, end, l, r, 2*node+1, v);
    tree[node] = tree[2*node] + tree[2*node+1];
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
        tree[i] = tree[2*i]+tree[2*i+1];
    }
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int idx, val;
            cin >> idx >> val;
            idx--;
            //update(idx, val, n);
            change(0, n-1, idx, idx, 1, val);
        }
        else{
            int low, high;
            cin >> low >> high;
            low--, high--;
            cout << query(0, n-1, low, high, 1) << endl;
        }
    }
    return 0;
}
