#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;
typedef long long ll;

struct Node{
    ll sum, prefix;
    Node(ll x = 0) : sum(x), prefix(max(0ll, x)){}
    Node(ll sum, ll prefix): sum(sum), prefix(prefix){}
    //friend keyword is used to access private members of the class
    friend Node operator+(const Node& a, const Node& b){
        return {a.sum + b.sum, max(a.prefix, a.sum+b.prefix)};
    }
};

vector<Node> Tree;

Node merge(Node& a, Node& b){
    Node res;
    res.sum = a.sum+b.sum;
    res.prefix = max(a.prefix, a.sum + b.prefix);
    return res;
}

void build(vector<ll>& a, ll start, ll end, ll idx){
    if(start == end){
        Tree[idx] = Node(a[start]);
        return;
    }
    ll mid = (start + end)/2;
    build(a, start, mid, 2*idx);
    build(a, mid+1, end, 2*idx+1);
    Tree[idx] = merge(Tree[2*idx], Tree[2*idx+1]);
//    Tree[idx] = Tree[2*idx] + Tree[2*idx+1];
}

Node queryUtil(ll start, ll end, ll l, ll r, ll idx){
    if(start > r || l > end){
        return 0;
    }
    if(start >= l && end <= r){
        return Tree[idx];
    }
    ll mid = (start+end)/2;
    Node left = queryUtil(start, mid, l, r, 2*idx);
    Node right = queryUtil(mid+1, end, l, r, 2*idx+1);
    return merge(left, right);
    //return left + right;
}

void update(ll start, ll end, ll pos, ll val, ll idx){
    if(start == end){
        Tree[idx] = Node(val);
        return ;
    }
    ll mid = (start+end)/2;
    if(mid >= pos){
        update(start, mid, pos, val, 2*idx);
    }
    else{
        update(mid+1, end, pos, val, 2*idx+1);
    }    
    Tree[idx] = merge(Tree[2*idx], Tree[2*idx+1]);
//    Tree[idx] = Tree[2*idx] + Tree[2*idx+1];
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    Tree.resize(4ll*n);
    build(a, 0, n-1, 1);
    while(q--){
        ll t, x, y;
        cin >> t >> x >> y;
        if(t == 1){
            update(0, n-1, x-1, y, 1);
        }
        else{
            cout << queryUtil(0, n-1, x-1, y-1, 1).prefix << endl;
        }
    }
    return 0;
}
