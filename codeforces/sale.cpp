#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int a[n], sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int i = 0;
    while(i < m){
        if(a[i] > 0){
            break;
        }
        sum += a[i];
        i++;
    }
    cout << ((sum<0) ? -sum : 0);
    return 0;
}
