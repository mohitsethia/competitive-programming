#include<iostream>
#include<algorithm>
#include<set>
#include<numeric>

using namespace std;

set<int> findFactors(int n){
    set<int> st;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            if(n/i == i) st.insert(i);
            else{
                st.insert(i);
                st.insert(n/i);
            }
        }
    }
    // if(*st.begin() == 1) st.erase(st.begin());
    return st;
}

int main(){
    int a, b, n;
    cin >> a >> b >> n;
    int g = gcd(a, b);
    set<int> st = findFactors(g);
    while(n--){
        int l, r;
        cin >> l >> r;
        auto it = st.lower_bound(l);
        if(it == st.end() || *it > r){
            cout << "-1\n";
        }
        else{
            int res = *it;
            while(it != st.end() && *it <= r){
                res = *it;
                it++;
            }
            cout << res << "\n";
        }
    }
    return 0;
}
