#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

#define endl '\n'
#define BLOCK 555
typedef long long ll;

struct query{
    int l, r, i;
};

query Q[200001];
ll ar[200001], ans[200001];
ll freq[200001] = {0};
int cnt = 0;

bool comp(query a, query b){
    if(a.l/BLOCK != b.l/BLOCK){
        return a.l/BLOCK < b.l/BLOCK;
    }
    return a.r < b.r;
}

void add(ll pos){
    freq[ar[pos]]++;
    if(freq[ar[pos]] == 1){
        cnt++;
    }
}

void remove(ll pos){
    freq[ar[pos]]--;
    if(freq[ar[pos]] == 0){
        cnt--;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, q;
    cin >> n >> q;
    map<ll, ll> coordinateCompress;
    ll compressedNum = 1;
    for(ll i = 0; i < n; i++){
        cin >> ar[i];
        if(coordinateCompress.find(ar[i]) != coordinateCompress.end()){
            ar[i] = coordinateCompress[ar[i]];
        }
        else{
            coordinateCompress[ar[i]] = compressedNum;
            ar[i] = compressedNum++;
        }
    }
    for(ll i = 0; i < q; i++){
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i, Q[i].l--, Q[i].r--;
    }
    sort(Q, Q+q, comp);
    ll ML = 0, MR = -1;
    for(ll i = 0; i < q; i++){
        ll L = Q[i].l;
        ll R = Q[i].r;

        while(ML > L){
            ML--, add(ML);
        }
        while(MR < R){
            MR++, add(MR);
        }

        while(L > ML){
            remove(ML), ML++;
        }
        while(MR > R){
            remove(MR), MR--;
        }
        ans[Q[i].i] = cnt;
    }
    for(ll i = 0; i < q; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
