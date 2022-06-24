#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
#define int long long
using namespace std;
bool isPrime(int n){
    if(n == 2 || n == 3){
        return true;
    }
    if(n%2 == 0 || n%3 == 0){
        return false;
    }
    for(int i = 5; i <= sqrt(n); i+=2){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
int solve(int& n){
    int s = sqrt(n);
    int first, second;
    for(int i = s-1; i > 0; i--){
        if(isPrime(i)){
            first = i;
            break;
        }
    }
    for(int i = s; ; i++){
        if(isPrime(i)){
            second = i;
            break;
        }
    }
    if(first*second == n){
        return first*second;
    }
    else if(first*second < n){
        int third;
        for(int i = second+1; ; i++){
            if(isPrime(i)){
                third = i;
                break;
            }
        }
        return (second*third <= n ? second*third : first*second);
    }
    else if(first*second > n){
        for(int i = first-1; i > 0; i--){
            if(isPrime(i)){
                second = i;
                break;
            }
        }
        if(first*second > n){
            first = second;
            for(int i = first -1; i > 0; i--){
                if(isPrime(i)){
                    second = i;
                    break;
                }
            }
        }
    }
    return first*second;
}
int32_t main(){
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        int n;
        cin >> n;
        int ans = solve(n);
        cout << "Case #" << tc << ": " << ans << endl;
    }
    return 0;
}
