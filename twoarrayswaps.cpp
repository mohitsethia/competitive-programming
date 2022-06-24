#include<iostream>
#include<set>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, sum = 0;
        cin >> n >> k;
        multiset<int> a;
        multiset<int> b;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            a.insert(x);
            sum += x;
        }
        for(int i = 0; i < n; i++){ 
            int x;
            cin >> x;
            b.insert(x);
        }
        for(int i = 0; i < k; i++){
            auto it = a.begin();
            if(*it < *--b.end()){
//                cout << *it << " " << *--b.end() << endl;
                sum -= *it;
                sum += *--b.end();
                a.erase(a.begin());
                b.erase(--b.end());
            }
        }
        cout << sum << endl;
    }
    return 0;
}
