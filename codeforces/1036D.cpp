#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int m;
    cin >> m;
    vector<int> b(m);
    for(int i = 0; i < m; i++) cin >> b[i];
    int i = 0, j = 0, prevA = 0, prevB = 0, len = 0;
    bool good = false;
    while(i < n && j < m){
        if(prevA + a[i] == prevB + b[j]){
            len++;
            i++;
            j++;
            prevA = prevB = 0;
            good = true;
            continue;
        }
        if(prevA + a[i] > prevB + b[j]){
            prevB += b[j++];
            good = false;
            continue;
        }
        prevA += a[i++];
        good = false;
        continue;
    }
    if(good && i == n && j == m){
        cout << len << "\n";
    }
    else{
        cout << "-1\n";
    }
    return 0;
}
