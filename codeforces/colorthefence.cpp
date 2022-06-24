#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[9];
    int sz = INT_MAX;
    int num = -1;
    for(int i = 0; i < 9; i++){
        cin >> a[i];
        if(a[i] <= sz){
            sz = a[i];
            num = i+1;
        }
    }
    int len = n/sz;
    int rem = n%sz;
    bool flag = true;
    string ans = "";
    while(flag){
        flag = false;
        for(int i = 8; i >= num; i--){
            if(sz+rem >= a[i]){
                ans += to_string(i+1);
                len--;
                rem -= (a[i]-sz);
                flag = true;
                break;
            }
        }
    }
    for(int i = 0; i < len; i++){
        ans += to_string(num);
    }
    if(ans.size() == 0){
        ans += "-1";
    }
    cout << ans << "\n";
    return 0;
}
