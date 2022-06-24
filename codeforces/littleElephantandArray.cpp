#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<unordered_map>

using namespace std;
#define int long long
#define endl '\n'
#define BLOCK 500

struct query{
    int l, r, i;
};

query Q[100005];
int ar[100005], ans[100005];
unordered_map<int, int> freq;

int cnt = 0;

bool comp(query a, query b){
    if(a.l/BLOCK != b.l/BLOCK){
        return a.l/BLOCK < b.l/BLOCK;
    }
    return a.r < b.r;
}

void add(int pos){
    int pre = freq[ar[pos]];
    freq[ar[pos]]++;
    int curr = freq[ar[pos]];
    if(pre == ar[pos]) cnt--;
    else if(curr == ar[pos]) cnt++;
}

void remove(int pos){
    int pre = freq[ar[pos]];
    freq[ar[pos]]--;
    int curr = freq[ar[pos]];
    if(pre == ar[pos]){
        cnt--;
    }
    else if(curr == ar[pos]){
        cnt++;
    }
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
    sort(Q, Q+q, comp);
    int ML = 0, MR = -1;
    for(int i = 0; i < q; i++){
        int L = Q[i].l, R = Q[i].r;

        while(ML > L){
            ML--;
            add(ML);
        }
        while(MR < R){
            MR++;
            add(MR);
        }

        while(ML < L){
            remove(ML);
            ML++;
        }
        while(MR > R){
            remove(MR);
            MR--;
        }

        ans[Q[i].i] = cnt;
    }
    for(int i =0; i < q; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
