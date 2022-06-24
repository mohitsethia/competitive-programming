#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>

#define int long long

using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        map<int, int> freq;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            freq[x] += (n-i)*(i+1);
        }
        int tot = n*(n+1)/2;
        for(int i = 0; i <= n+1; i++){
            if(!freq.count(i)){
                cout << i << "\n";
                break;
            }
            else{
                int occ = tot-freq[i];
                if(occ < k){
                    k -= occ;
                }
                else{
                    cout << i << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}
