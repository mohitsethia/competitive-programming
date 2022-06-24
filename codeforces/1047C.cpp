#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

#define int long long
using namespace std;
const int N = 1.5e7 + 1;

vector<int> prime(N), countdiv(N);

void sieve(){
    for(int i = 2; i*i < N; i++){
        if(!prime[i]){
            for(int j = i*i; j < N; j += i)
                prime[j] = i;
        }
    }
    for(int i = 1; i < N; i++){
        if(!prime[i]) prime[i] = i;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int g = a[0];
    bool flag = true;
    for(int i = 1; i < n; i++){
        g = gcd(g, a[i]);
        if(a[i] != a[i-1]) flag = false;
    }
    if(flag){
        cout << "-1\n";
        return 0;
    }
    for(int i = 0; i < n; i++){
        a[i] /= g;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int k = a[i];
        while(k > 1){
            int d = prime[k];
            countdiv[d]++;
            ans = max(ans, countdiv[d]);
            while(k%d == 0) k /= d;
        }
    }
    cout << n-ans << "\n";
    return 0;
}
