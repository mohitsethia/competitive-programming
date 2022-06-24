#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

struct FenwickTree{
    long long N;
    vector<long long> tree;
    void init(long long n){
        N = n;
        tree.assign(n+1, 0);
    }
    void update(long long idx, long long val){
        while(idx <= N){
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }
    void updateMax(long long idx, long long val){
        while(idx <= N){
            tree[idx] = max(tree[idx], val);
            idx += (idx & -idx);
        }
    }
    long long pref(long long idx){
        long long ans = 0;
        while(idx > 0){
            ans += tree[idx];
            idx -= (idx & -idx);
        }
        return ans;
    }
    long long rsum(long long l, long long r){
        return pref(r)-pref(l-1);
    }
    long long prefMax(long long idx){
        long long ans = -2e9;
        while(idx > 0){
            ans = max(ans, tree[idx]);
            idx -= (idx & -idx);
        }
        return ans;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, q;
    cin >> n >> q;
    FenwickTree bit;
    bit.init(n);
    long long x;
    for(long long i = 0; i < n; i++){
        cin >> x;
        bit.update(x, 1);
    }
    while(q--){
        cin >> x;
        if(x >= 1){
            bit.update(x, 1);
        }
        else{
            x = -x;
            long long l = 1, r = n;
            long long ans;
            while(l <= r){
                long long mid = (l+r)/2;
                long long curr_pref = bit.pref(mid);
                if(curr_pref >= x){
                    ans = mid;
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            bit.update(ans, -1);
        }
    }
    for(long long i = 1; i <= n; i++){
        if(bit.pref(i)){
            cout << i << "\n";
            return 0;
        }
    }
    cout << "0\n";
    return 0;
}
