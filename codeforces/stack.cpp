#include<iostream>
#include<stack>

using namespace std;
int main(){
    int x = 1, i;
    stack <int> str;
    while(x != 0){
        cout << "Enter 1 to push an element" << endl;
        cout << "Enter 2 to pop" << endl;
        cin >> x;
        cout << x;
        int a;
        if(x == 1){
            cin >> a;
            str.push(a);
        }
        else if(x == 2){
            if(str.empty()){
                cout << "stack is empty";
            }
            else{
                cout << str.top() << endl;
                str.pop();
            }
        }
    }
    return 0;
}

