#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> vis(n+1), a(n+1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i+1 <= n; i++){
            int mn = n+1;
            int idx = 1;
            for(int j = 1; j+1 <= n; j++){
                if(a[j+1] < mn && !vis[j]){
                    mn = a[j+1];
                    idx = j;
                }
            }
            if(a[idx+1] < a[idx]){
                swap(a[idx], a[idx+1]);
            }
            vis[idx] = 1;
        }
        for(int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}
