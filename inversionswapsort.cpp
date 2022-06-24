#include<iostream>
using namespace std;
bool mycompare(pair<int, int> x, pair<int, int> y){
    if(x.first == y.first){
        return x.second > y.second;
    }
    else return x.first > y.first;
}
int main(){
    int n;
    cin >> n;
    pair<int, int> a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
        b[i].first = a[i].first;
        b[i].second = b[i].second;
    }
    sort(b, b+n);
    for(int i = 0; i < n; i++){
        if(a[i].first != b[i].first){
            cout << a[i].second+1 << " " << b[i].second+1 << endl;
        }
    }
    return 0;
}   
