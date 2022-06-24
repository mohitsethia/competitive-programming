//finding the upper and lower bound of an sorted array using binary_search stl
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int q;
    cin >> q;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        bool present = bianry_search(a, a+n, x);
        if(present){
            int* lb = lower_bound(a, a+n, x);
            int* ub = upper_bound(a, a+n, x);
            lb = lb - a;
            ub = ub - a;
            cout << lb << " " << ub << endl;
        }
        else{
            cout << "-1 -1" << endl;
        }
    }
    return 0;
}
