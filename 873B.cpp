#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    char c;
    for(int i = 0; i < n; i++){
        cin >> c;
        a[i] = (c == '1') ? 1 : -1;
    }
    map<int, int> mp;
    int sum = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        if(sum == 0){
            ans = i+1;
        }
        else if(mp.find(sum) != mp.end()){
            ans = max(ans, i-mp[sum]);
        }
        else{
            mp[sum] = i;
        }
    }
    cout << ans << endl;
    return 0;
}
