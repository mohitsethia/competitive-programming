#include<iostream>
#include<algorithm>
#include<map>


using namespace std;


const int bitsCount = 32;
const int N = 1e6+5;
int prefAnd[bitsCount][N];
int prefXor[N];

void findPrefixAnd(vector<int> &a, int n){
    for(int i = 0; i < bitsCount; i++){
        prefAnd[i][0] = (a[0] >> i)&1;
        for(int j = 1; j < n; j++){
            prefAnd[i][j] = prefAnd[i][j-1] + ((a[j] >> i)&1);
        }
    }
}

void findPrefixXor(vector<int> &a, int n){
    for(int i = 0; i < n; i++){
        prefXor[i] = i ? prefXor[i-1]^a[i] : a[i];
    }
}

bool query(int l, int r){
    int And = 0;
    for(int i = 0; i < bitsCount; i++){
        int x = 0;
        if(l == 0){
            x = prefAnd[i][r];
        }
        else{
            x = prefAnd[i][r] - prefAnd[i][l-1];
        }
        if(x == r-l+1){
            And |= (1ll << i);
        }
    }
    int Xor = prefXor[r] ^ (l > 0 ? prefXor[l-1] : 0);
    return And > Xor;
}

int solve(vector<int> &a){
    int res = 0;
    int mask = 0;
    map<int, int> mp;
    int n = a.size();
    mp[0] = -1;
    for(int i = 0; i < n; i++){
        mask ^= a[i];
        if(!mp.count(mask)){
            mp[mask] = i;
        }
        res = max(res, i-mp[mask]);
    }
    return res;
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
    }
    int ans = 0;
    int mask = 0;
    for(int bit = 31; bit >= 0; bit--){
        mask |= (1 << bit);
        for(int i = 0; i < n; i++){
            if((a[i] & (1<<bit))){
                vector<int> aa;
                while(i < n && (a[i]&(1<<bit))){
                    aa.push_back(a[i++]&mask);
                }
                ans = max(ans, solve(aa));
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

