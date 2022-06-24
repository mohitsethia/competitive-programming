#include<iostream>
using namespace std;
int median(int *a, int *b, int n){
    int lo1 = 0, lo2 = 0, k = 0, arr[n];
    while(lo1 < n && lo2 < n){
        if(a[lo1] <= b[lo2]){
            arr[k] = a[lo1];
            lo1++;
            k++;
        }
        else{
            arr[k] = b[lo2];
            k++;
            lo2++;
        }
    }
    if(lo1 == n){
        while(lo2 < n){
            arr[k] = b[lo2];
            k++;
            lo2++;
        }
    }
    if(lo2 == n){
        while(lo1 < n){
            arr[k] = a[lo1];
            k++;
            lo1++;
        }
    }
    return arr[n-1];
}
int main(){
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    cout << median(a, b, n);
    return 0;
}
