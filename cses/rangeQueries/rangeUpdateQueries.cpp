/*
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
vector<int> Tree;
int merge(int x, int y){
    return x+y;
}
int query(int start, int end, int l, int r, int node, int v){
    if(start > r || l > end){
        return 0;
    }
    if(start >= l && r >= end){
        if(v != -1){
            Tree[node] += v;
        }
        return Tree[node];
    }
    int mid = (start+end)/2;
    int left = query(start, mid, l, r, 2*node, v);
    int right = query(mid+1, end, l, r, 2*node+1, v);
    int sum = left + right;
    return sum + Tree[node];
}
//void update(int start, int end, int idx, int val, int node){
//    if(start == end){
//        Tree[node] = val;
//        return;
//    }
//    int mid = (start+end)/2;
//    if(idx <= mid){
//        update(start, mid, idx, val, 2*node);
//    }
//    else{
//        update(mid+1, end, idx, val, 2*node+1);
//    }
//    Tree[node] = merge(Tree[2*node], Tree[2*node+1]);
//    return;
//}
int update(int start, int end, int l, int r, int node, int v){
    if(start >= l && end <= r){
        if(v != -1){
            Tree[node] += v;
        }
        return Tree[node];
    }
    if(start > r || l > end){
        return 0;
    }
    int mid = (start+end)/2;
    int left = update(start, mid, l, r, 2*node, v);
    int right = update(mid+1, end, l, r, 2*node+1, v);
    int sum = left+right;
    return sum + Tree[node];
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
    for(int i = 0; i < (int)a.size(); i++){
        Tree[base+i] = a[i];
    }
//    for(int i = base-1; i >= 1; i--){
//        Tree[i] = merge(Tree[2*i], Tree[2*i+1]);
//    }
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int l, r, u;
            cin >> l >> r >> u;
//            int actual_l = query(0, base-1, l-1, l-1, 1);
//            int actual_r = query(0, base-1, r, r, 1);
//            update(0, base-1, l-1, actual_l+u, 1);
//            update(0, base-1, r, actual_r-u, 1);
            query(0, base-1, l-1, r-1, 1, u);
        }
        else{
            int k;
            cin >> k;
            cout << query(0, base-1, k-1, k-1, 1, -1) << endl;
        }
    }
    return 0;
}
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
vector<int> Tree;
int merge(int x, int y){
    return x+y;
}
int query(int start, int end, int l, int r, int node){
    if(start > r || l > end){
        return 0;
    }
    if(start >= l && r >= end){
        return Tree[node];
    }
    int mid = (start+end)/2;
    int left = query(start, mid, l, r, 2*node);
    int right = query(mid+1, end, l, r, 2*node+1);
    return merge(left, right);
}
void update(int start, int end, int idx, int val, int node){
    if(start == end){
        Tree[node] = val;
        return;
    }
    int mid = (start+end)/2;
    if(idx <= mid){
        update(start, mid, idx, val, 2*node);
    }
    else{
        update(mid+1, end, idx, val, 2*node+1);
    }
    Tree[node] = merge(Tree[2*node], Tree[2*node+1]);
    return;
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
    Tree.resize(2*n);
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int l, r, u;
            cin >> l >> r >> u;
            int actual_l = query(0, n-1, l-1, l-1, 1);
            int actual_r = query(0, n-1, r, r, 1);
            update(0, n-1, l-1, actual_l+u, 1);
            if(r == n){
            	continue;
            }
            update(0, n-1, r, actual_r-u, 1);
        }
        else{
            int k;
            cin >> k;
            cout << a[k-1] + query(0, n-1, 0, k-1, 1) << endl;
        }
    }
    return 0;
}
