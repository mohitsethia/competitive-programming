#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    int cm = INT_MAX, sum = 0;
    for(int i = 0; i < m; i++){
        sum = 0;
        for(int j = 0; j < n; j++){
            sum = sum | (a[j] & b[i]);
        }
        cm = min(cm, sum);
    }
    cout << cm << endl;
    return 0;
}
