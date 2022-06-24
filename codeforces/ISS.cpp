#include<iostream>
#include<algorithm>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;
cpp_int gcd(cpp_int a, cpp_int b){
    return ((b==0) ? a : gcd(b, a%b));
}
cpp_int solve(cpp_int n){
    cpp_int res = 0;
    for(cpp_int i = 1; i <= 2*n; i++){
        res += gcd(n+i*i, n+(i+1)*(i+1));
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cpp_int n;
        cin >> n;
        cpp_int res = solve(n);
        cout << res << endl;
    }
    return 0;
}
