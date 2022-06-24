#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    vector<int> res(n);
    if(n < 3 || a[0] < a[1] + a[2]){
        cout << "YES\n";
        int i = 0, j = n-1;
        for(int k = 0; k < n; k++){
            if(k%2 == 0){
                res[i++] = a[k];
            }
            else{
                res[j--] = a[k];
            }
        }
        for(auto it: res) cout << it << " ";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}
