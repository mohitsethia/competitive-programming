#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<numeric>

#define int long long

using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<int> p(n);
    set<int> unknown;
    for(int i = 0; i < n; i++){
        unknown.insert(i);
    }
    auto ask = [&](int i, int j){
        cout << "? " << i+1 << " " << j+1 << endl;
        int k;
        cin >> k;
        return k;
    };
    while(unknown.size() > 1){
        int idx1 = *unknown.begin();
        unknown.erase(unknown.begin());
        int idx2 = *unknown.begin();
        unknown.erase(unknown.begin());
        int a = ask(idx1, idx2);
        int b = ask(idx2, idx1);
        if(a > b){
            p[idx1] = a;
            unknown.insert(idx2);
        }
        else{
            p[idx2] = b;
            unknown.insert(idx1);
        }
    }
    int s = accumulate(p.begin(), p.end(), 0ll);
    p[*unknown.begin()] = n*(n+1)/2 - s;
    cout << "! ";
    for(int i = 0; i < n; i++){
        cout << p[i] << " ";
    }
    cout << endl;
    return 0;
}
