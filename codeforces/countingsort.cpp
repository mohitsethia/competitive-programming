//find the largest element
//initialize the array of length largest+1 with 0
//count the freq of each element
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n], ma = INT_MIN;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ma = max(a[i], ma);
    }
    int b[ma+1];
    memset(b, 0, sizeof b);
    for(int i = 0; i < n; i++){
        b[a[i]]++;
    }
    for(int i = 0; i < ma + 1; i++){
        while(b[i] != 0){
            cout << i << " ";
            b[i] -= 1;
        }
    }
    return 0;
}
