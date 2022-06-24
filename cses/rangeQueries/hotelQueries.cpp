#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
vector<int> Tree;
int merge(int x, int y){
    return (x > y ? x : y);
}
void update(int pos, int val){
    Tree[pos] = val;
    pos /= 2;
    while(pos){
        Tree[pos] = merge(Tree[2*pos], Tree[2*pos+1]);
        pos /= 2;
    }
}
void debug(){
    cout << " #Debug ";
    for(int i = 0; i < Tree.size(); i++){
        cout << Tree[i] << " ";
    }
    cout << endl;
}
int query(int val, int base){
    if(Tree[1] < val){
        return 0;
    }
    int idx = 1;
    while(idx < base){
        if(Tree[2*idx] < val){
            idx = 2*idx+1;
        }
        else{
            idx = 2*idx;
        }
    }
//    cout << " idx " << idx << " and idx-base+1 = " << idx-base+1 << endl;
    update(idx, Tree[idx]-val);
   // debug();
    return idx-base+1;
}
int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<int> hotel(n);
    for(int i = 0; i < n; i++){
        cin >> hotel[i];
    }
    int base = 1;
    while(base < n){
        base *= 2;
    }
    Tree.resize(2*base);
    for(int i = 0; i < (int)hotel.size(); i++){
        Tree[base+i] = hotel[i];
    }
    for(int i = base-1; i >= 1; i--){
        Tree[i] = merge(Tree[2*i], Tree[2*i+1]);
    }
 //   debug();
    while(m--){
        int r;
        cin >> r;
        cout << query(r, base) << " ";
    }
    return 0;
}
