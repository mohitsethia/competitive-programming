#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        unsigned long long int xy, i, n, a, count = 0, cnt = 0, prod;
        cin >> n >> a;
        prod = a;
        for(i = 1; i < n; i++){
            if(2*i-1 <= n*n){
                count = 2*i-1;
                prod *= pow(a, count);
                a = prod;   
                cnt += 2*i -1;
            }
        }
        cnt += 2*i - 1;
        count = 2*i - 1;
        long long int nleft = (n*n) - cnt;
        long long int x = pow(a, count);
        if(nleft != 0){
            cout << (nleft*x)%1000000007 << endl;
        }
        else{
            cout << x%1000000007 << endl;
        }
    }
    return 0;
}   
