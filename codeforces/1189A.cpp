#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int zeroes = 0, ones = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') zeroes++;
        else ones++;
    }
    if(zeroes != ones) {
        cout << "1\n" << s;
    }
    else {
        cout << "2\n" << s[0] << " ";
        s.erase(s.begin());
        cout << s << "\n";
    }
    return 0;
}
