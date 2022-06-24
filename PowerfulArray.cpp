#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;

#define int long long
#define endl '\n'
#define BLOCK 555

struct query{
    int l, r, i;
};

query Q[200001];
int ar[200001], ans[200001];
int freq[1000001];
int product = 0;
bool myComparator(query a, query b){
    if(a.l/BLOCK != b.l/BLOCK){
        return a.l/BLOCK < b.l/BLOCK;
    }
    return a.r < b.r;
}

void add(int pos){
    int cnt = freq[ar[pos]];
    freq[ar[pos]]++;
    product -= (cnt*cnt) * ar[pos];
    cnt++;
    product += (cnt*cnt) * ar[pos];
}

void remove(int pos){
    int cnt = freq[ar[pos]];
    freq[ar[pos]]--;
    product -= (cnt*cnt) * ar[pos];
    cnt--;
    product += (cnt*cnt) * ar[pos];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    for(int i = 0; i < q; i++){
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i, Q[i].l--, Q[i].r--;
    }
    sort(Q, Q+q, myComparator);
    int ML = 0, MR = -1;
    for(int i = 0; i < q; i++){
        int L = Q[i].l;
        int R = Q[i].r;

        while(ML > L){
            ML--, add(ML);
        }
        while(MR < R){
            MR++, add(MR);
        }

        while(L > ML){
            remove(ML), ML++;
        }
        while(R < MR){
            remove(MR), MR--;
        }

        ans[Q[i].i] = product;
    }
    for(int i = 0; i < q; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
