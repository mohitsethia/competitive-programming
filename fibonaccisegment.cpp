#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int32_t main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n <= 2){
        cout << n << endl;
        return 0;
    }
    int i = 0, x = 2, m = 0;
    while(i < n - 2){
        if(a[i] + a[i+1] == a[i+2]){
            i++;
            x++;
        }
        else{
            m = max(m, x);
            x = 2;
            i++;
        }
    }
    m = max(m, x);
    cout << m << endl;
    return 0;
}
