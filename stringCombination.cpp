#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void generate(string& in, string out, int i, vector<string>& str, int n){
    if(i == n){
        out += '\0';
        str.push_back(out);
        return;
    }    
    generate(in, out, i+1, str, n);
    out += in[i];
    generate(in, out, i+1, str, n);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string in, out;
    cin >> in;
    vector<string> str;
    int n = in.length();
    generate(in, out, 0, str, n);
    sort(str.begin(), str.end());
    for(string s: str){
        if(s[0] == '\0'){
            continue;
        }
        cout << s << endl;
    }
    return 0;
}

