#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int area(int x2, int x3){
    return x3 - x2;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> s;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                s.insert(area(a[i], a[j]));
            }
        }
        cout << s.size() << endl;
    }
    return 0;
}
