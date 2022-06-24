#include<iostream>
#include<unordered_map>
using namespace std;
int longestarraywithsumk(int *a, int n, int k){
    unordered_map<int, int> mp;
    int pre = 0, len = 0;
    for(int i = 0; i < n; i++){
        pre += a[i];
        if(pre == k){
            len = max(len, i + 1);
        }
        if(mp.find(pre-k)!= mp.end()){
            len = max(len, i - mp[pre-k]);
        }
        else{
            mp[pre] = i;
        }
    }
    return len;
}
int main(){
    int n, k;
    cin >> n >> k;
    int *a = new int[n];
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }
    cout << longestarraywithsumk(a, n, k) << endl;
    return 0;
}
