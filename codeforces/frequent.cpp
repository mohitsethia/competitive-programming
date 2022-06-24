#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
#include<unordered_map>

using namespace std;

#define int long long
#define endl '\n'
#define BLOCK 555
struct query{
    int l, r, i;
};

query Q[300001];
int ans[300001];
int ar[300001];
int freq[300001];
int freqOfFreq[300001];
int curr_max = 0;
//unordered_map<int, int> freq;

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
    if(freqOfFreq[pre] != 0)
        freqOfFreq[pre]--;
    freqOfFreq[curr]++;
    if(curr_max < curr){
        curr_max = curr;
    }
}

void remove(int pos){
    int pre = freq[ar[pos]];
    freq[ar[pos]]--;
    int curr = freq[ar[pos]];
    freqOfFreq[pre]--;
    freqOfFreq[curr]++;
    if(curr < curr_max){
        while(freqOfFreq[curr_max] == 0){
            curr_max--;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        int q;
        cin >> q;
        for(int i = 0; i < n; i++){
            cin >> ar[i];
            ar[i] += 100000;
        }
        for(int i = 0; i < q; i++){
            cin >> Q[i].l >> Q[i].r;
            Q[i].i = i, Q[i].l--, Q[i].r--;
        }
        sort(Q, Q+q, comp);
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

            while(ML < L){
                remove(ML), ML++;
            }
            while(MR > R){
                remove(MR), MR--;
            }
            ans[Q[i].i] = curr_max;
        }
        for(int i = 0; i < q; i++){
            cout << ans[i] << endl;
        }
        for(int i = 0; i <= 200000; i++) freq[i] = freqOfFreq[i] = curr_max = 0;
    }
    return 0;
}
