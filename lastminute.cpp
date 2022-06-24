#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        set<int> s;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(s.find(a[i]) != s.end()){
                s.insert(a[i]+1);
            }
            else{
                s.insert(a[i]);
            }
        }
        cout << s.size() << endl;
        
    }
    return 0;
}
