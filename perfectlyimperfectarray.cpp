#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i< n; i++){
            cin >> a[i];
        }
        int cons = 0, d = 0;
        sort(a, a+n);
        int c = sqrt(a[0]);
        if(a[0] != c*c){
            d++;
        }
        for(int i = 1; i < n; i++){
            if(a[i] == a[i-1]+1){
                cons++;
                break;
            }
            int k = sqrt(a[i]);
            if(a[i] != k*k){
                d++;
                break;
            }
        }
        if(cons || d){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
