#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int> > a(n, vector<int>(k));
    vector<int> each(k);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cin >> a[i][j];
            if(a[i][j] == 1)
                each[j]++;
        }
    }
    int mid = (n+1)/2;
    for(int i = 0; i < k; i++){
        if(each[i] > mid){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
