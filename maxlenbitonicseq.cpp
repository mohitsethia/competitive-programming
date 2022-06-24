#include<iostream>
#include<algorithm>
using namespace std;
int bitonic(int n, int a[]){
    int inc[n], dec[n], max1 = 1, max2 = 1;
    inc[0] = 1;
    dec[n-1] = 1;
    for(int i = 1; i < n; i++){
        inc[i] = (a[i] >= a[i-1]) ? inc[i-1]+1 : 1;
    }
    for(int i = n-2; i >= 0; i--){
        dec[i] = (a[i] >= a[i+1]) ? dec[i+1]+1 : 1;
    }
   int max1 = inc[0] + dec[0] - 1;
   for(int i = 1; i < n ;i++){
       max1 = max(max1, inc[i]+dec[i] -1);
   }
    return max1+max2-1;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        cout << bitonic(n, a) << endl;
    }
    return 0;
}
