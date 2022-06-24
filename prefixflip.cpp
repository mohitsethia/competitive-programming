#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string a, b;
        cin >> n >> a >> b;
        vector<int> v;
        for(int i = n-1; i >= 0; i--){
            if(a[i] !=  b[i]){
                if(a[0] == b[i]){
                    v.push_back(1);
                    a[0] = '0' + !(a[0] - '0');
                }
                reverse(a.begin(), a.begin() + i + 1);
                for(int j = 0; j <= i; j++){
                    a[j] = '0' + !(a[j] - '0');
                }
                v.push_back(i+1);
            }
        }
        cout << v.size() << endl;
        for(int it : v){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
