#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
void rotate(vector<int>& arr){
    int n = (int)arr.size();
    int temp = arr[n-1];
    for(int i = n-1; i > 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}
bool is_sorted(vector<int>& arr){
    int n = (int)arr.size();
    if(n < 3){
        return true;
    }
    for(int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        bool found = true;
        for(int i = 0; i < n-1; i++){
            if(abs(a[i+1] - a[i]) != 1 && abs(a[i+1] - a[i]) != n-1){
                found = false;
                break;
            }
        }
        if(found) puts("YES");
        else puts("NO");
    }
    return 0;
}
