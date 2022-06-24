#include<iostream>
#include<fstream>
using namespace std;
int main(){
    string s = "NO";
    cout << s << endl;
    string line;
    while (std::getline(std::cin, line)){
        cout << s << endl;
        if(line.empty()){
            break;
        }
    }
    return 0;
}
