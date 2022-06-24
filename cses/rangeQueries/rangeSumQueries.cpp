#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
vector<int> tree;
int query(int start, int end, int l, int r, int node){
	//no overlap case
	if(r < start || l > end){
		return 0;
	}
	
	//complete overlap case
	if(start >= l && r >= end){
		return tree[node];
	}
	
	//partial overlap case
	int mid = (start+end)/2;
	int left = query(start, mid, l, r, 2*node);
	int right = query(mid+1, end, l, r, 2*node+1);
	
	return left+right;
}
void update(vector<int>& a);

void build(vector<int>& a, int start, int end, int node){
	if(start == end){
		tree[node] = a[start];
		return;
	}
	int mid = (start+end)/2;
	build(a, start, mid, 2*node);
	build(a, mid+1, end, 2*node+1);
	tree[node] = tree[2*node]+tree[2*node+1];
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
	//build(a, 0, n-1, 1);
	for(int i = 0; i < (int)a.size(); i++){
	 	tree[n+i] = a[i];
	}
	for(int i = n-1; i >= 1; i--){
	 	tree[i] = tree[2*i] + tree[2*i+1];
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		l--, r--;
		cout << query(0, n-1, l, r, 1) << endl;
	}
    return 0;
}
