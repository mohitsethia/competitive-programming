#include<iostream>
#include<vector>

using namespace std;
int main(){
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c)){
        if(a == 0 && b == 0 && c == 0){
            break;
        }
        if(b + (b - a) == c){
            int x = c + (b - a);
            cout << "AP " << x << endl;
        }
        else{
            int cr = b/a;
            if(a * cr == b){
                cout << "GP " << c*cr << endl;
            }
        }
    }
    return 0;
}
