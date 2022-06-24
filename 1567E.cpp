#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

#define int long long
using namespace std;

const int N = 2e5+5;

struct node{
    int ans;
    int pref;
    int suf;
    int first, last;
    int s;
    node(){
        ans = 0, pref = 0, suf = 0, s = 0;
        first = INT_MAX;
        last = -1;
    }
    node(int x){
        ans = pref = suf = s = 1;
        first = last = x;
    }
};

node t[4*N];
int a[N];

node merge(node a, node b){
    node c;
    c.ans = a.ans+b.ans;
    c.pref = a.pref;
    c.suf = b.suf;
    c.first = a.first;
    c.last = b.last;
    c.s = a.s+b.s;
    if(a.last <= b.first){
        c.ans += a.suf * b.pref;
        if(a.s == a.pref) c.pref = a.s + b.pref;
        else c.pref = a.pref;
        if(b.s == b.suf) c.suf = a.suf + b.s;
        else c.suf = b.suf;
    }
    return c;
}

void build(int idx, int l, int r){
    if(l == r){
        t[idx] = node(a[l]);
        return;
    }
    int mid = (l+r)>>1;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    t[idx] = merge(t[2*idx], t[2*idx+1]);
}

void update(int idx, int l, int r, int pos, int val){
    if(l > pos || r < pos) return;
    if(l == r && l == pos){
        t[idx] = node(val);
        return;
    }
    int mid = (l+r)/2;
    if(pos <= mid)
        update(2*idx, l, mid, pos, val);
    else
        update(2*idx+1, mid+1, r, pos, val);
    t[idx] = merge(t[2*idx], t[2*idx+1]);
}

node query(int idx, int l, int r, int start, int end){
    if(l > end || r < start) return node();
    if(l >= start && r <= end) return t[idx];
    int mid = (l+r)>>1;
    node left = query(2*idx, l, mid, start, end);
    node right = query(2*idx+1, mid+1, r, start, end);
    return merge(left, right);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    build(1, 0, n-1);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int pos, val;
            cin >> pos >> val;
            update(1, 0, n-1, pos-1, val);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n-1, l-1, r-1).ans << "\n";
        }
    }

    return 0;
}
