#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
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
    return ans;
}
int main(){
    int t;
    cin >> t;
    int tc = 1;
    while(tc <= t){
        cout << "Case #" << tc++ << ": " << solve() << "\n";
    }
    return 0;  
}

