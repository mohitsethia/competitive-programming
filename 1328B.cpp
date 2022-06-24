#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    long long t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        for(int first = n-2; first >= 0; first--){
            int i = n-1 - first;
            if(i >= k){
                int second = n-k;
                string ans(n, 'a');
                ans[first] = ans[second] = 'b';
                cout << ans << "\n";
                break;
            }
            k -= i;
        }
    }
    return 0;
}
