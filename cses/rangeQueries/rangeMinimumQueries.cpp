#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<climits>
using namespace std;
#define int long long
vector<int> tree;
int query(int start, int end, int l, int r, int node){
    //no overlap Case
    if(start > r || end < l){
        return INT_MAX;
    }
    //complete Overlap Case
    if(start >= l && end <= r){
        return tree[node];
    }
    //Partial Overlap Case
    int mid = (start+end)/2;
    int left = query(start, mid, l, r, 2*node);
    int right = query(mid+1, end, l, r, 2*node+1);
    return min(left, right);
}
int32_t main(){
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
    for(int i = 0; i < (int) a.size(); i++){
        tree[n+i] = a[i];
    }
    for(int i = n-1; i >= 1; i--){
        tree[i] = min(tree[2*i], tree[2*i+1]);
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(0, n-1, l, r, 1) << endl;
    }
    return 0;
}
