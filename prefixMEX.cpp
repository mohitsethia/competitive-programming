#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>

#define int long long
using namespace std;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i && a[i] < a[i-1]){
            cout << "-1\n";
            return 0;
        }
        else if(i == 0 && a[i] > 1){
            cout << "-1\n";
            return 0;
        }
    }
    vector<int> b(n, -1);
    unordered_map<int, int> already;
    for(int i = 1; i < n; i++){
        if(a[i] != a[i-1]){
            b[i] = a[i-1];
            already[b[i]] = 1;
        }
    }
    already[a[n-1]] = 1;
    int there = 0;
    for(int i = 0; i < n; i++){
        while(already.count(there)) there++;
        if(b[i] == -1){
            already[there] = 1;
            b[i] = there;
        }
    }
    for(int i = 0; i < n; i++){
        cout << b[i] << " ";
    }
}
