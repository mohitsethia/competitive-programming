#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
bool calculate(vector<int> a, int& n, int& target){
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        int minIdx = i;
        if(a[i] == i+1){
            ans++;
            continue;
        }
        for(int j = i+1; j < n; j++){
            if(a[j] == i+1){
                minIdx = j;
            }
        }
        ans += (minIdx-i+1);
        reverse(a.begin()+i, a.begin()+minIdx+1);
    }
    if(ans == target){
        return true;
    }
    return false;
}
int solve(int& n, int& k){
    if(k < n-1 || k >= n*(n+1)/2){
        return -1;
    }
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        a[i] = i+1;
    }
    do{
        if(calculate(a, n, k)){
             for(int& i: a){
                 cout << i << " ";
             }
             cout << endl;
            return 0;
        }
    }
    while(next_permutation(a.begin(), a.end()));
    return 0;
}
int main(){
    int t, tc = 1;
    cin >> t;
    while(tc <= t){
        int n, k;
        cin >> n >> k;
        cout << "Case #" << tc++ << ": ";
        if(solve(n, k) == -1){
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
