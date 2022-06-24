#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;

#define int long long 
#define BLOCK 555
#define endl '\n'

struct query{
    int l, r, i;
};

query Q[200001];
int ar[30001], ans[200001];
int freq[1000001];
int cnt = 0;

bool myComparator(query a, query b){
    if(a.l/BLOCK != b.l/BLOCK){
        return a.l/BLOCK < b.l/BLOCK;
    }
    return a.r < b.r;
}

void add(int pos){
    freq[ar[pos]]++;
    if(freq[ar[pos]]==1) cnt++;
}

void remove(int pos){
    freq[ar[pos]]--;
    if(freq[ar[pos]] == 0) cnt--;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    cin >> q;
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
        ans[Q[i].i] = cnt;
    }
    for(int i = 0; i < q; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
