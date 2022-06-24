#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int k = n-1;
        sort(a.begin(), a.end());
        while(k > 0 && (a[0] + a[k])/2 < a[k]){
            k--;
        }
        cout << n-k-1 << '\n';
    }
    return 0;
}
