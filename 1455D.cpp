#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

#define int long long
using namespace std;

bool isSorted(vector<int> &a){
    for(int i = 1; i < (int)a.size(); i++){
        if(a[i] < a[i-1]) return false;
    }
    return true;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int res = 0;
        while(!isSorted(a)){
            int p = -1;
            for(int i = 0; i < n; i++){
                if(a[i] > x){
                    p = i;
                    swap(a[i], x);
                    res++;
                    break;
                }
            }
            if(p == -1){
                res = -1;
                break;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
