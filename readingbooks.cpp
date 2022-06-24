#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
int32_t main(){
    int n, k;
    cin >> n >> k;
    vector<int> both, alice, bob;
    int a, b, t;
    for(int i = 0; i < n; i++){
        cin >> t >> a >> b;
        if(a == 1 && b == 1){
            both.push_back(t);
        }
        else if(a == 1){
            alice.push_back(t);
        }
        else if(b == 1){
            bob.push_back(t);
        }
    }
    int d = both.size();
    int e = alice.size();
    int f = bob.size();
    int g = k - d;
    if(g < 0 || (g-e <= 0 && g-f <= 0)){
        sort(both.begin(), both.end());
        sort(alice.begin(), alice.end());
        sort(bob.begin(), bob.end());
        int sum = 0, p = 0, q = 0, r = 0;
        while(k--){
            if(p < d && e > 0 && f > 0 && q < e && r < f){
                if(both[p] <= alice[q]+bob[r]){
                    sum += both[p];
                    p++;
                }
                else{
                    sum += alice[q] + bob[r];
                    r++;
                    q++;
                }
            }
            else if(d > 0 && p < d){
                sum += both[p];
                p++;
            }
            else{
                sum += alice[q] + bob[r];
                r++;
                q++;
            }
        }
        cout << sum << endl;
    }
    else{
        cout << -1 << endl;
    }
    return 0;
}
