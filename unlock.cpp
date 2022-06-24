#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int *a = new int[n];
    unordered_map<int, int> mp;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mp[a[i]] = i;
    }
    for(int i = n; i > 0 && k > 0; i--){
        int best = n - i + 1;
        int ind = mp[i];
        if(best != ind){
            swap(a[best], a[ind]);
            k--;
            mp[a[best]] = best;
            mp[a[ind]] = ind;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
