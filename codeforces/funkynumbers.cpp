#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
#define int long long
int32_t main(){
    int n;
    cin >> n;
    set<int> s;
    for(int i = 1; i < 100001; i++){
        s.insert(i*(i+1)/2);
    }
    for(set<int>::iterator it = s.begin(); it != s.end(); it++){
        if(n-*it > 0 && s.count(n-*it)){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
