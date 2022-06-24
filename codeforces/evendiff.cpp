#include<iostream>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n], odd = 0, even = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]%2){
            odd++;
        }
        else{
            even++;
        }
    }
    cout << min(even, odd) << endl;
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
