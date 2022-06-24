#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
vector<int> Tree;
int merge(int x, int y){
    return x^y;
}
int query(int start, int end, int l, int r, int node){
    if(l > end || start > r){
        return 0;
    }
    if(start >= l && end <= r){
        return Tree[node];
    }
    int mid = (start+end)/2;
    int left = query(start, mid, l, r, 2*node+1);
    int right = query(mid+1, end, l, r, 2*node+2);
    return merge(left, right);
}
void buildTree(vector<int>& a, int start, int end, int node){
    if(start == end){
        Tree[node] = a[start];
        return;
    }
    int mid = (start+end)/2;
    buildTree(a, start, mid, 2*node+1);
    buildTree(a, mid+1, end, 2*node+2);
    Tree[node] = merge(Tree[2*node+1], Tree[2*node+2]);
    return;
}
int32_t main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int& i: a){
        cin >> i;
    }
    int base = 1;
    while(base < n){
        base *= 2;
    }
    Tree.resize(2*base);
    buildTree(a, 0, n-1, 0);
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(0, n-1, l, r, 0) << endl;
    }
    return 0;
}
