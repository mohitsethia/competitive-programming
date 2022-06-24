#pragma GCC optimize("O2")
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
vector<int> Tree;

void build(vector<int>& a, int start, int end, int node, int toggle){
    if(start == end){
        Tree[node] = a[start];
        return;
    }
    int mid = (start+end)/2;
    build(a, start, mid, 2*node, toggle-1);
    build(a, mid+1, end, 2*node+1, toggle-1);
    if(toggle%2){
        Tree[node] = Tree[2*node] | Tree[2*node+1];
    }
    else{
        Tree[node] = Tree[2*node] ^ Tree[2*node+1];
    }
    return;
}

void update(int start, int end, int idx, int val, int node, int toggle){
    if(start == end){
        Tree[node] = val;
        return;
    }
    int mid = (start+end)/2;
    if(idx <= mid){
        update(start, mid, idx, val, 2*node, toggle-1);
    }
    else{
        update(mid+1, end, idx, val, 2*node+1, toggle-1);
    }
    if(toggle%2){
        Tree[node] = Tree[2*node] | Tree[2*node+1];
    }
    else{
        Tree[node] = Tree[2*node] ^ Tree[2*node+1];
    }
    return;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int base = (1 << n);
    vector<int> a(base);
    for(int i = 0; i < base; i++){
        cin >> a[i];
    }
    Tree.resize(2*base);
    build(a, 0, base-1, 1, n);
    while(m--){
        int p, b;
        cin >> p >> b;
        p--;
        update(0, base-1, p, b, 1, n);
        cout << Tree[1] << endl;
    }
    return 0;
}
