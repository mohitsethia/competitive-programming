#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        int x1, p1;
        cin >> x1 >> p1;
        s1 = to_string(x1);
        int x2, p2;
        cin >> x2 >> p2;
        s2 = to_string(x2);
        int n1 = s1.length();
        int n2 = s2.length();
        if(n1+p1 > n2 + p2){
            cout << ">\n";
            continue;
        }
        else if(n1 + p1 < n2+p2){
            cout << "<\n";
            continue;
        }
        if(n1 == n2){
            if(p1 > p2){
                cout << ">";
            }
            else if(p1 < p2){
                cout << "<";
            }
            else{
                if(x1 < x2){
                    cout << "<";
                }
                else if(x1 > x2){
                    cout << ">";
                }
                else{
                    cout << "=";
                }
            }
        }
        else{
            if(p1 < p2){
                while(p1 < p2){
                    x2 *= 10;
                    p2--;
                }
            }
            else{
                while(p2 < p1){
                    x1 *= 10;
                    p1--;
                }
            }
            if(x1 > x2){
                cout << ">";
            }
            else if(x1 < x2){
                cout << "<";
            }
            else{
                cout << "=";
            }
        }
        cout << "\n";
    }
    return 0;
}
