#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
int main(){
    long double n, x, y;
    cin >> n >> x >> y;
    set<long double> s;
    int inf = 0;
    for(int i = 0; i < n; i++){
        long double x2, y2;
        cin >> x2 >> y2;
        if(y == y2){
            inf = 1;
        }
        else{
            s.insert((x-x2)/(y-y2));
        }
    }
    cout << s.size() + inf << endl; 
    return 0;
}
