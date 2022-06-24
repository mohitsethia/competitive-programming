#include<iostream>
using namespace std;
void insertionsort(int *a, int n){
    int i, j, key;
    for(int i = 1; i < n; i++){
        key = a[i];
        j = i-1;
        while(j >= 0 and a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    insertionsort(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
