#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int idx = -1, mx = 0;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > mx){
            mx = a[i];
            idx = i;
        }
    }
    if(a[idx] != 1)
        a[idx] = 1;
    else
        a[idx] = 2;
    sort(a, a+n);
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    return 0;
}
