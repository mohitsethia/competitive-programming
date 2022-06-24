#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
#define int long long
vector<int> tree;
int query(int start, int end, int l, int r, int node){
    if(start > r || l > end){
        return 0;
    }
    if(start >= l && end <= r){
        return tree[node];
    }
    int mid = (start+end)/2;
    int left = query(start, mid, l, r, 2*node);
    int right = query(mid+1, end, l, r, 2*node+1);
    return (left+right)%3;
}
int32_t main(){
    string s;
    cin >> s;
    int len = s.length();
    while(__builtin_popcount(len) != 1){
        len++;
    }
    tree.resize(2*len);
    for(int i = 0; i < (int)s.length(); i++){
        tree[len+i] = s[i]-'0';
    }
    for(int i = len-1; i >= 1; i--){
        int rightBit = 0;
        int a = tree[2*i];
        int b = tree[2*i+1];
        int cnt = 1;
        while(b != 0){
            cnt++;
            b /= 2;
        }
        int bit = (pow(2, cnt) * a) + tree[2*i+1];
        tree[i] = bit;
    }
    cout << endl;
    for(int i = 1; i < tree.size(); i++){
        cout << tree[i] << " ";
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(0, len-1, l, r, 1) << endl;
    }
    return 0;
}
