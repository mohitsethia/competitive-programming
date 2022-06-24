#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int N = 3e5 + 1;

int sum[N];

int get_sum(int l, int r){
    if(l > r){
        return 0;
    }
    return (l%2) ? sum[r]-sum[l-1] : sum[l-1]-sum[r];
}

int ifEliminated(int l, int r, int mid){
    if((mid-l+1)%2){
        return get_sum(l, mid-1)+get_sum(mid+1, r);
    }
    return get_sum(l, mid-1)-get_sum(mid+1, r);
}

int solve(int l, int r){
    if(l == r) return l;
    int left = l;
    int right = r;
    while(left < right){
        int mid = (left+right)>>1;
        int leftQuery = ifEliminated(l, r, left);
        if(leftQuery == 0) return left;
        int midQuery = ifEliminated(l, r, mid);
        if(midQuery == 0) return mid;
        int rightQuery = ifEliminated(l, r, right);
        if(rightQuery == 0) return right;
        bool sign1 = leftQuery < 0 ? false : true;
        bool sign2 = midQuery < 0 ? false : true;
        if(sign1 == sign2){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        sum[0] = 0;
        for(int i = 1; i <= n; i++){
            sum[i] = sum[i-1] + (s[i-1] == '+' ? 1 : -1)*(i%2 ? 1 : -1);
        }
        for(int query = 0; query < q; query++){
            int l, r;
            cin >> l >> r;
            if(get_sum(l, r) == 0){
                cout << "0\n";
                continue;
            }
            bool even = false;
            if((r-l+1)%2 == 0){
                cout << "2\n" << l << " ";
                even = true;
                l++;
            }
            if(!even) cout << "1\n";
            cout << solve(l, r) << "\n";
        }
    }
    return 0;
}
