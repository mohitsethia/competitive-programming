#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

#define int long long

using namespace std;

void print(int n){
    cout << "YES\n";
    cout << n-1 << "\n";
    for(int i = 1; i < n; i += 2){
        cout << i << " " << i+1 << " " << i+2 << "\n";
    }
    for(int i = 1; i < n; i += 2){
        cout << i << " " << i+1 << " " << n << "\n";
    }
}

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n%2 == 0){
        int Xor = 0;
        for(int i = 0; i < n; i++){
            Xor ^= a[i];
        }
        if(Xor != 0){
            cout << "NO\n";
            return 0;
        }
        print(n-1);
    }
    else print(n);
    return 0;
}
