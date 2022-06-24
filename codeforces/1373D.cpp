#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i%2 == 0){
                sum += a[i];
            }
        }
        int increase = 0, fi1 = 0;
        for(int i = 0; i < n-1; i += 2){
            increase += a[i+1]-a[i];
            fi1 = max(fi1, increase);
            if(increase < 0) increase = 0;
        }
        int fi2 = 0;
        increase = 0;
        for(int i = 1; i < n-1; i += 2){
            increase += a[i]-a[i+1];
            fi2 = max(fi2, increase);
            if(increase < 0) increase = 0;
        }
        if(fi1 <= 0 && fi2 <= 0){
            cout << sum << "\n";
        }
        else{
            cout << sum + max(fi1, fi2) << "\n";
        }
    }
    return 0;
}
