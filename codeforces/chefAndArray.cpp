#include<iostream>
#include<algorithm>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;
#define int long long
#define endl '\n'

const int MAX_N = 200005;
const int LOG = 17;

int arr[MAX_N];
int m[MAX_N][LOG];
int logt[MAX_N];

int query(int L, int R){
    if(R < L) swap(L, R);
    int length = R - L + 1;
    int k = logt[length];
    return max(m[L][k], m[R - (1 << (k)) + 1][k]);
}

void precompute(vector<int>& arr, int& n){
    logt[1] = 0;
    for(int i = 2; i < MAX_N-4; i++){
        logt[i] = logt[i/2] + 1;
    }
    int j = logt[n];
    for(int k = 1; k <= j; k++){
        for(int i = 0; i + (1 << k) <= n; i++){
            m[i][k] = max(m[i][k-1], m[i + (1 << (k-1))][k-1]);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        m[i][0] = a[i];
    }
    precompute(a, n);
    int M, x, y;
    cin >> M >> x >> y;
    int sum = 0;
    while(M--){
        sum += query(x, y);
        x = (x + 7)%(n-1);
        y = (y + 11)%n;
    }
    cout << sum << endl;
    return 0;
}




















/*
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<climits>

using namespace std;
#define int long long
#define endl '\n'

int query(int start, int end, int l, int r, int node, vector<int>& Tree){
    if(start > r || end < l){
        return INT_MIN;
    }
    if(start >= l && end <= r){
        return Tree[node];
    }
    int mid = (start+end)/2;
    int left = query(start, mid, l, r, 2*node, Tree);
    int right = query(mid+1, end, l, r, 2*node+1, Tree);
    return max(left, right);
}

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int base = 1;
    while(base < n){
        base *= 2;
    }
    vector<int> Tree(2*base);
    for(int i = 0; i < (int) a.size(); i++){
        Tree[base+i] = a[i];
    }
    for(int i = base-1; i >= 1; i--){
        Tree[i] = max(Tree[2*i], Tree[2*i+1]);
    }
    int m, l, r;
    cin >> m >> l >> r;
    int sum = query(0, base-1, min(l, r), max(l, r), 1, Tree);
    m--;
    while(m--){
        l = (l+7)%(n-1);
        r = (r+11)%n;
        sum += query(0, base-1, min(l, r), max(l, r), 1, Tree);
    }
    cout << sum << endl;
    return 0;
}
*/
