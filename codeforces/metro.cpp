#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    bool ok = false;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    if(a[0] == 0){
        cout << "NO\n";
        return 0;
    }
    if(a[s-1] == 1){
        cout << "YES\n";
        return 0;
    }
    if(b[s-1] == 0){
        cout << "NO\n";
        return 0;
    }
    for(int i = s; i < n; i++){
        if(a[i] == 1 && b[i] == 1){
            ok = true;
        }
    }
    if(ok){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}

// NO case
// if the metro doesn't start in the first station then it is not possible
// if the metro starts at station 1 and doesn't stop anywhere greater than station number s or it should stop where going to the left direction is possible or simply we would check if at station s if both the ways are not open yet then he will not be able to go to s
