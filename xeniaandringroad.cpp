#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int32_t main(){
    int n, m;
    cin >> n >> m;
    int a[m], sum = 0;
    cin >> a[0];
    sum += (a[0]-1);
    for(int i = 1; i < m; i++){
        cin >> a[i];
        if(a[i] < a[i-1]){
            sum += (n-a[i-1]+a[i]);
        }
        else{
            sum += a[i] - a[i-1];
        }
    }
    cout << sum << endl;
    return 0;
}
