#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define endl '\n'
typedef long long ll;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string a;
        cin >> a;
        ll numberOfSheeps = 0;
        for(ll i = 0; i < n; i++){
            if(a[i] == '*'){
                numberOfSheeps++;
            }
        }
        numberOfSheeps = (numberOfSheeps+1)/2;
        ll v = 0, idx = -1;
        for(ll i = 0; i < n; i++){
            if(a[i] == '*'){
                v++;
                if(v == numberOfSheeps){
                    idx = i;
                    break;
                }
            }
        }
        ll ans = 0;
        ll cnt = 0;
        for(ll i = idx; i >= 0; i--){
            if(a[i] == '.'){
                cnt++;
            }
            else{
                ans += cnt;
            }
        }
        cnt = 0;
        for(ll i = idx+1; i < n; i++){
            if(a[i] == '.'){
                cnt++;
            }
            else{
                ans += cnt;
            }
        }
        cout << ans << endl;
    }
    return 0;
}


/*
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define int long long
int32_t main(){
int t;
cin >> t;
while(t--){
int n;
string s;
cin >> n >> s;
vector<int> oneIndices;
for(int i = 0; i < n; i++){
    if(s[i] == '*'){
        oneIndices.push_back(i);
    }
}
if(oneIndices.size() == 0){
    cout << "0\n";
    continue;
}
int middleOfOneIndices  = (oneIndices.size()+1)/2-1;
int centerIndex  = oneIndices[middleOfOneIndices];
int minSwaps = 0;
for (int i=0; i<oneIndices.size(); i++) {
    minSwaps += abs(oneIndices[middleOfOneIndices]-oneIndices[i])-abs(middleOfOneIndices-i);
  }
cout << minSwaps << endl;
}
return 0;
}
*/
