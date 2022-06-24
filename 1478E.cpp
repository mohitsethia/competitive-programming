#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

void build_tree(int *arr, int *tree, int start, int end, int index){
    if(start == end){
        tree[index] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    build_tree(arr, tree, start, mid, 2*index);
    build_tree(arr, tree, mid+1, end, 2*index+1);
    tree[index] = tree[2*index] + tree[2*index+1];
}

void update(int *arr, int *tree, int *lazy, int start, int end, int index, int start_range, int end_range, int value){
    if(start > end){
        return;
    }
    if(lazy[index] != -1){
        tree[index] += (end-start+1) * lazy[index];
        if(start != end){
            lazy[2*index] = lazy[index];
            lazy[2*index+1] = lazy[index];
        }
        lazy[index] = -1;
    }
    if(start_range > end || end_range < start) return;
    if(start_range <= start && end_range >= end){
        tree[index] = (end-start+1)*value;
        lazy[index] = value;
        if(start != end){
            lazy[2*index] = lazy[index];
            lazy[2*index+1] = lazy[index];
        }
        lazy[index] = -1;
        return;
    }
    int mid = (start+end)/2;
    update(arr, tree, lazy, start, mid, 2*index, start_range, end_range, value);
    update(arr, tree, lazy, mid+1, end, 2*index+1, start_range, end_range, value);
    tree[index] = tree[2*index] + tree[2*index+1];
}

int query(int *tree, int *lazy, int start, int end, int index, int left, int right){
    if(start > end){
        return 0;
    }
    if(lazy[index] != -1){
        tree[index] = (end-start+1)*lazy[index];
        if(start != end){
            lazy[2*index] = lazy[index];
            lazy[2*index+1] = lazy[index];
        }
        lazy[index] = -1;
    }
    if(start > right || end < left){
        return 0;
    }
    if(start >= left && end <= right){
        return tree[index];
    }
    int mid = (start +end)/2;
    int val1 = query(tree, lazy, start, mid, 2*index, left, right);
    int val2 = query(tree, lazy, mid+1, end, 2*index+1, left, right);
    return val1+val2;
}

void solve(){
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    vector<pair<int, int> > queries(q);
    for(int i = 0; i < q; i++){
        cin >> queries[i].first >> queries[i].second;
    }
    int arr1[n];
    int arr2[n];
    for(int i = 0; i < n; i++){
        arr1[i] = a[i] == '1';
        arr2[i] = b[i] == '1';
    }
    int *tree = new int[4*n]();
    int *lazy = new int[4*n];
    for(int i = 0; i < 4*n; i++){
        lazy[i] = -1;
    }
    build_tree(arr2, tree, 0, n-1, 1);
    int counter = 0;
    for(int i = q-1; i >= 0; i--){
        int left = queries[i].first, right = queries[i].second;
        left--, right--;
        int value = query(tree, lazy, 0, n-1, 1, left, right);
        int length = right-left+1;
        int ones = value;
        int zeroes = length - ones;
        if(ones > zeroes){
            update(arr2, tree, lazy, 0, n-1, 1, left, right, 1);
        }
        else if(zeroes > ones){
            update(arr2, tree, lazy, 0, n-1, 1, left, right, 0);
        }
        else{
            counter = 1;
            break;
        }
    }
    for(int i = 0; i < n; i++){
        arr2[i] = query(tree, lazy, 0, n-1, 1, i, i);
        if(arr2[i] != arr1[i]){
            counter = 1;
        }
    }
    cout << (counter == 0 ? "YES\n" : "NO\n") << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
