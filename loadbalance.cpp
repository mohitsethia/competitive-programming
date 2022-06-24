#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<set>

using namespace std;
int main(){
    int n, i, val, a[9000];
    while(1){
        int max_load = 0, load = 0;
        cin >> n;
        if(n == -1){
            break;
        }
        for(int i = 0; i < n; i++){
            cin >> a[i];
            load += a[i];
        }
        if(load%n != 0){
            cout << -1 << endl;
            continue;
        }
        load = load/n;
        int diff = 0;
        for(int i = 0; i < n; i++){
            diff += (a[i] - load);
            int ans = max(diff, -diff);
            max_load = max(max_load, ans);
        }
        cout << max_load << endl;
    }
    return 0;
}
