#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

#define int long long
using namespace std;

const int N = 3e6 + 5;
int n;
int a[N], rp[N], mx[N];
bool sieve[N];
multiset<int> s;

void preprocess(){
	fill(sieve + 2, sieve + N, 1);
	fill(mx + 1, mx + N, 1);

    int idx = 0;
    for(int i = 2; i < N; i++){
        if(sieve[i]){
            ++idx;
            rp[i] = idx;
        }
        for(int j = 2; i*j < N; j++){
            sieve[i*j] = false;
            mx[i*j] = i;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    preprocess();

    cin >> n;
    for(int i = 1; i <= 2*n; i++){
        cin >> a[i];
        s.insert(a[i]);
    }
    vector<int> ans;
    while(s.size()){
        int largest = *s.rbegin();
        if(sieve[largest]){
            ans.push_back(rp[largest]);
            s.erase(s.find(largest));
            s.erase(s.find(rp[largest]));
        }
        else{
            ans.push_back(largest);
            s.erase(s.find(largest));
            s.erase(s.find(mx[largest]));
        }
    }
    for(auto &it: ans){
        cout << it << " ";
    }

    return 0;
}
