#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int ask(int t, int i, int j, int x){
    cout << "? " << t << " " << i << " " << j << " " << x << endl;
    int s;
    cin >> s;
    return s;
}
int findNth(int n){
    for(int i = 1; i < n; i += 2){
        int r = ask(1, i, i+1, n-1);
        if(r == n){
            return i+1;
        }
        else if(r == n-1){
            r = ask(1, i+1, i, n-1);
            if(r == n){
                return i;
            }
        }
    }
    return n;
}
void solve(){
    int n;
    cin >> n;
    int nth = findNth(n);
    int arr[n+1];
    arr[nth] = n;
    for(int i = 1; i <= n; i++){
        if(i == nth){}
        else{
            arr[i] = ask(2, i, nth, 1);
        }
    }
    cout << "! ";
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
