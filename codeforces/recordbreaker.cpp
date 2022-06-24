#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define int long long
int32_t main(){
    int t, tc = 1;
    cin >> t;
    while(tc <= t){
        int n;
        cin >> n;
        int a[n], count = 0, mx = INT_MIN;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int i = 0;
        for(i = 0; i < n-1; i++){
            if(a[i+1] < a[i] && a[i] > mx){
                mx = a[i];
//                cout << i << " ";
                count++;
            }
            if(i == n-2 && mx == INT_MIN){
                mx = a[i];
            }
        }
        if(i == n-1 && a[i] > mx){
            count++;
        }
        cout << "Case #" << tc << ": " << count << endl;
        tc++;
    }
    return 0;
}
