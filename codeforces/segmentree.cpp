#include<iostream>
#include<vector>
using namespace std;
class segmentree{
    public:
    vector<int> st;
    void init(int n){
        st.resize(4*n, 0);
    }
    //building flattened binary tree
    void build(int *a, int start, int end, int node){
        if(start == end){
            st[node] = a[start];
            return;
        }
        int mid = (start+end)/2;
        build(a, start, mid, 2*node + 1);
        build(a, mid+1, end, 2*node + 2);
        st[node] = st[2*node+1] + st[2*node + 2];
        return;
    }
    int query(int start, int end, int l, int r, int node){
        //no overlap case
        if(start > r || end < l){
            return 0;
        }
        //complete overlap case
        if(start >= l && end <= r){
            return st[node];
        }
        //partial overlap
        int mid = (start+end)/2;
        int left = query(start, mid, l, r, 2*node + 1);
        int right = query(mid+1, end, l, r, 2*node + 2);
        return left + right;
    }
    void update(int *a, int start, int end, int val, int idx, int node){
        if(start == end){
            st[node] = val;
            a[idx] = val;
            return;
        }
        int mid = (start+end)/2;
        if(idx <= mid){
            update(a, start, mid, val, idx, 2*node+1);
        }
        else{
            update (a, mid+1, end, val, idx, 2*node+2);
        }
        st[node] = st[2*node+1] + st[2*node+2];
        return;
    }
};
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        segmentree tree;
        tree.init(n);
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        tree.build(a, 0, n-1, 0);

//        for(int i = 0; i < 4*n; i++){
//            cout << tree.st[i] << " ";
//        }
        while(q--){
            int type;
            cin >> type;
            if(type == 1){
                int idx, val;
                cin >> idx >> val;
                idx--;
                tree.update(a, 0, n-1, val, idx, 0);
            }
            else{
                int l, r;
                cin >> l >> r;
                l--, r--;
                cout << tree.query(0, n-1, l, r, 0) << endl;
            }
        }
        
    }
    return 0;
}
