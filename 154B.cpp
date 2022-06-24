#include<iostream>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

#define int long long

void print(set<int> s){
    for(auto i: s){
        cout << i << " ";
    }
    cout << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    set<int> present;
    auto factorize = [&](int x){
        vector<int> res;
        for(int i = 2; i*i <= x; i += (i&1)+1){
            if(x%i == 0){
                res.push_back(i);
                while(x%i == 0){
                    x /= i;
                }
            }
        }
        if(x > 1) res.push_back(x);
        return res;
    };
    while(m--){
        char c;
        int x;
        cin >> c >> x;
        if(c == '+'){
            // print(present);
            if(present.count(x)){
                cout << "Already on\n";
            }
            else{
                int there = 0;
                vector<int> factors = factorize(x);
                for(auto it: factors){
                    if(mp.count(it)){
                        there = mp[it];
                        break;
                    }
                }
                if(there){
                    cout << "Conflict with " << there << "\n";
                }
                else{
                    cout << "Success\n";
                    for(auto it: factors){
                        mp[it] = x;
                    }
                    present.insert(x);
                }
            }
        }
        else{
            if(present.count(x)){
                cout << "Success\n";
                vector<int> factors = factorize(x);
                for(auto it: factors){
                    mp.erase(it);
                }
                present.erase(x);
            }
            else{
                cout << "Already off\n";
            }
        }
    }
    return 0;
}
