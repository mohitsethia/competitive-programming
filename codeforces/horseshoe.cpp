#include<iostream>
#include<set>
using namespace std;
#define int long long
int32_t main(){
    set<int> s;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    s.insert(d);
    cout << 4 - s.size() << endl;
    return 0;
}
