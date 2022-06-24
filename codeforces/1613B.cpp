#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

const int N = 2e5+5;
int a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        for(int i = 0; i < n/2; i++){
            cout << a[n-i-1] << " " << a[0] << "\n";
        }
    }
    return 0;
}
