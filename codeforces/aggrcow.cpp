#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
#define int long long
bool canweplace(int *a, int n, int c, int curr_min){
    int cows = 1;
    int pos = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] - pos >= curr_min){
            pos = a[i];
            cows++;
            if(cows == c){
                return true;
            }
        }
    }
    return false;
}
int findposition(int *a, int n, int c){
    int s = 0;
    int e = a[n-1];
    int ans = -1;
    while(s < e){
        int mid = (s + e)/2;
        if(canweplace(a, n, c, mid)){
            ans = max(ans, mid);
            s = mid + 1;
        }
        else{
            e = mid;
        }
    }
    return ans;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        int stall[n];
        for(int i = 0; i < n; i++){
            cin >> stall[i];
        }
        sort(stall, stall+n);
        cout << findposition(stall, n, c) << endl;
    }
    return 0;
}
