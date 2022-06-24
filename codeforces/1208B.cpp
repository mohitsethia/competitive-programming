#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

#define int long long

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = n;
    for(int i = 0; i < n; i++){
        unordered_map<int, int> freq;
        bool isValid = true;
        for(int j = 0; j < i; j++){
            if(++freq[a[j]] == 2){
                isValid = false;
                break;
            }
        }
        int minIndex = n;
        for(int j = n-1; j >= 0; j--){
            if(++freq[a[j]] == 1){
                minIndex = j;
            }
            else break;
        }
        if(isValid){
            ans = min(ans, minIndex-i);
        }
    }
    cout << ans << "\n";
    return 0;
}
