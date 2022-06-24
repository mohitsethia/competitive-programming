#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cnt = 0, idx = -1;
    for(int i = 0; i < n-1; i++){
        if(a[i] > a[i+1]){
            cnt++;
            idx = i;
        }
    }
    if(a[n-1] > a[0]){
        idx = n-1;
        cnt++;
    }
    if(!cnt){
        cout << "0" << endl;
    }
    else if(cnt > 1){
        cout << "-1" << endl;
    }
    else{
        cout << n-1-idx << endl;
    }
    return 0;
}
