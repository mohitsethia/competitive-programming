#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

#define int long long

using namespace std;

const int N = 2e5 + 2;
const int MOD = 1e9 + 7;
int n;
map<int, int> exponents[N];
multiset<int> mn[N];
bool is_prime[N];
int prime_divisor[N];

void sieve(){
    for(int p = 2; p < N; p++){
        is_prime[p] = true;
    }
    for(int p = 2; p < N; p++){
        if(is_prime[p]){
            prime_divisor[p] = p;
            for(int a = 2*p; a < N; a += p){
                prime_divisor[a] = p;
                is_prime[a] = false;
            }
        }
    }
}

vector<pair<int, int> > factorization(int x){
    vector<pair<int, int> > v;
    while(x != 1){
        int cnt = 0;
        int p = prime_divisor[x];
        while(x%p == 0){
            x /= p;
            cnt++;
        }
        v.emplace_back(p, cnt);
    }
    return v;
}

int get_min(int p){
    if((int)mn[p].size() == n){
        return *mn[p].begin();
    }
    return 0ll;
}

int answer = 1;

void query(int i, int x){
    for(pair<int, int> pr: factorization(x)){
        int p = pr.first;
        int e = pr.second;
        int old_min = get_min(p);
    
        int &tmp = exponents[p][i];
        if(tmp != 0)
            mn[p].erase(mn[p].find(tmp));

        tmp += e;
        mn[p].insert(tmp);

        int new_min = get_min(p);
        for(int rep = 0; rep < new_min-old_min; rep++){
            answer = answer*p % MOD;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int q;
    cin >> n >> q;
    int x, i;
    for(i = 0; i < n; i++){
        cin >> x;
        query(i, x);
    }
    while(q--){
        cin >> i >> x;
        i--;
        query(i, x);
        cout << answer << "\n";
    }
    return 0;
}
