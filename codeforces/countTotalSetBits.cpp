#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int power(int x){
    int k = 0;
    while((1 << k) <= x){
        k++;
    }
    return k-1;
}

int main(){
    int n;
    cin >> n;
    int ans = 0;
    while(n){
        int x = power(n);
        ans += (1<<(x-1))*x;
        ans += n-(1 << x)+1;
        n = n-(1 << x);
    }
    cout << ans << "\n";
    return 0;
}
