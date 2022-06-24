#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int minSwaps(int *a, int n){
    pair<int, int> arr[n];
    for(int i = 1; i < n; i++){
        arr[i].first = a[i];
        arr[i].second = i;
    }
    sort(arr, arr+n);
    vector<bool> visited(n, false);
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(visited[i] || arr[i].second == i){
            continue;
        }
        int cycle_size = 0;
        int j = i;
        while(!visited[j]){
            visited[j] = true;
            j = arr[j].second;
            cycle_size++;
        }
        if(cycle_size > 0){
            ans += (cycle_size - 1);
        }
    }
    return ans;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[n+1], count = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= m; i++){
            int x, y, k = 1, l = 1;
            cin >> x >> y;
            for(int j = 0; j <= n; j++){
                if(a[j] == x){
                    k = j;
                }
                if(a[j] == y){  
                    l = j;
                }
            }
            if(k != l){
                if(a[k] == l || a[l] == k){
//                  cout << a[k] << " " << k << " " << a[l] << " " << l << " ";
                    swap(a[k], a[l]);
                    count++;
//                    cout << count << " ";
//                  cout << a[k] << " " << a[l] << endl;
                }
            }
        }
        int ans = minSwaps(a, n + 1);
//        cout << endl;
        if(count >= ans - 1){
            cout << ans << endl;
        }
        else{
            cout << ans + (ans - count - 1) << endl;
        }
    }
    return 0;
}
