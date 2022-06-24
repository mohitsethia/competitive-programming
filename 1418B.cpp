#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n), c;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
            if(!b[i]){
                c.emplace_back(a[i]);
            }
        }
        sort(c.begin(), c.end(), greater<int>());
        int j = 0;
        for(int i = 0; i < n; i++){
            if(b[i]){
                cout << a[i] << " ";
            }
            else{
                cout << c[j] << " ";
                j++;
            }
        }
        cout << endl;
    }
    return 0;
}
