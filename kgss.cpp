#include<iostream>
#include<algorithm>
#include<cstdio>
#include<climits>
#include<vector>
using namespace std;
#define int long long

struct Node{
    Node(int x, int y):m1(x), m2(y){}
    Node(){}
    int m1, m2;
};
Node merge(Node x, Node y){
    vector<int> v{x.m1, x.m2, y.m1, y.m2};
    sort(v.begin(), v.end(), greater<int>());
    Node temp;
    temp.m1 = v[0];
    temp.m2 = v[1];
    return temp;
}
vector<Node> Tree;
void buildTree(vector<int>& a, int start, int end, int idx){
    if(start == end){
        Tree[idx].m1 = a[start];
        Tree[idx].m2 = INT_MIN;
        return;
    }
    int mid = (start+end)/2;
    buildTree(a, start, mid, 2*idx+1);
    buildTree(a, mid+1, end, 2*idx+2);
    Tree[idx] = merge(Tree[2*idx+1], Tree[2*idx+2]);
    return;
}
Node queryUtil(int start, int end, int l, int r, int idx){
    if(end < l || start > r){
        Node null(INT_MIN, INT_MIN);
        return null;
    }
    if(start >= l && end <= r){
        return Tree[idx];
    }
    int mid = (start+end)/2;
    Node left = queryUtil(start, mid, l, r, 2*idx+1);
    Node right = queryUtil(mid+1, end, l, r, 2*idx+2);
    return merge(left, right);
}
int query(int start, int end, int l, int r, int idx){
    Node res = queryUtil(start, end, l, r, idx);
    int ans = res.m1+res.m2;
    return ans;
}
void update(vector<int>& a, int start, int end, int idx, int val, int node){
    if(start == end){
        Tree[node].m1 = val;
        a[idx] = val;
        return;
    }
    int mid = (start+end)/2;
    if(idx <= mid){
        update(a, start, mid, idx, val, 2*node+1);
    }
    else{
        update(a, mid+1, end, idx, val, 2*node+2);
    }
    Tree[node] = merge(Tree[2*node+1], Tree[2*node+2]);
    return;
}
int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
    }
    int base = 1;
    while(base < n){
        base *= 2;
    }
    Tree.resize(2*base);
    buildTree(a, 0, base-1, 0);
    //for(int i = 0; i < (int)a.size(); i++){
      //  Tree[base+i].m1 = a[i];
        //Tree[base+i].m2 = INT_MIN;
    //}
    //for(int i = base-1; i >= 1; i--){
      //  Tree[i] = merge(Tree[2*i], Tree[2*i+1]);
    //}
    int q;
    cin >> q;
    while(q--){
        char type;
        cin >> type;
        if(type == 'Q'){
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << query(0, base-1, l, r, 0) << endl;
        }
        else{
            int idx, val;
            cin >> idx >> val;
            idx--;
            update(a, 0, base-1, idx, val, 0);
        }
    }
    return 0;
}
