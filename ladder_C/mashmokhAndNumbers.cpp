#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
#define endl '\n'
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    if(n == 1 && k == 0){
        cout << "1\n";
    }
    else if(k < n/2 || (n == 1 && k > 0)){
        cout << "-1\n";
    }
    else{
        vector<int> a;
        int rem = k - (n/2 - 1);
        a.push_back(rem);
        a.push_back(2*rem);
        int all = (n/2 - 1);
        int c = (rem%2 == 0 ? rem+1 : rem+2);
        n -= 2;
        while(n > 1){
            a.push_back(c);
            a.push_back(c+2);
            c += 4;
            n -= 2;
        }
        if(n == 1){
            a.push_back(c);
        }
        for(int i = 0; i < (int) a.size(); i++){
            cout << a[i] << " ";
        }
    }
    return 0;
}
