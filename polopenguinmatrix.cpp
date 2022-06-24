#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(n*m);
    cin >> a[0];
    for(int i = 1; i < n*m; i++){
        cin >> a[i];
        if(a[i]%d != a[i-1]%d){
            cout << "-1\n";
            return 0;
        }
    }
    sort(a.begin(), a.end());
    int k = a[n*m/2];
    int c = 0;
    for(int i = 0; i < n*m; i++){
        c += abs(k-a[i])/d;
    }
    cout << c;
    return 0;
}

