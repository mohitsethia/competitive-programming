#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int cnt[101];

int32_t main(){
    int n, q;
    cin >> n >> q;
    while(q--){
        int t, k, d;
        cin >> t >> k >> d;
        int sum = 0;
        int counter = 0;
        for(int i = 1; i <= n; i++){
            if(cnt[i] < t){
                counter++;
            }
            if(counter == k) break;
        }
        if(counter < k){
            cout << "-1\n";
        }
        else{
            counter = 0;
            for(int i = 1; i <= n; i++){
                if(cnt[i] < t){
                    sum += i;
                    cnt[i] = t+d-1;
                    counter++;
                }
                if(counter == k) break;
            }
            cout << sum << "\n";
        }
    }
    return 0;
}
