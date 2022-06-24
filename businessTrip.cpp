#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 12, k;
    cin >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    int sum = 0;
    if(k == 0){
        cout << "0\n";
    }
    else{
        for(int i = 0; i < n; i++){
            sum += a[i];
            if(sum >= k){
                cout << i+1 << endl;
                return 0;
            }
        }
        cout << "-1" << endl;
    }
    return 0;
}
