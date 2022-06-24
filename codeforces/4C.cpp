#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> db;
    while(n--){
        string s;
        cin >> s;
        if(db.count(s)) {
            db[s]++;
            s += to_string(db[s]-1);
            cout << s << "\n";
        }
        else {
            db[s]++;
            cout << "OK\n";
        }
    }
    return 0;
}
