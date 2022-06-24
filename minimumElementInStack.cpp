#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

class MinStack{
    stack<int> st;
    int min_element;
public:
    MinStack(){
        st = stack<int>();
        min_element = INT_MAX;
    }
    void push(int x){
        if(st.empty()){
            st.push(x);
            min_element = x;
            return;
        }
        if(x < min_element){
            st.push(2*x - min_element);
            min_element = x;
        }
        else{
            st.push(x);
        }
    }
    void pop(){
        int temp = st.top();
        st.pop();
        if(temp < min_element){
            min_element = 2*min_element - temp;
        }
    }
    int top(){
        if(st.top() < min_element){
            return min_element;
        }
        return st.top();
    }
    int getMin(){
        return min_element; 
    }
};

int main(){
    MinStack *obj = new MinStack();
    while(1){
        cout << "1. push\n2. getMin\n3. pop\n4. top\n";
        int type;
        cin >> type;
        switch(type){
            case 1:
                int x;
                cin >> x;
                obj->push(x);
                break;
            case 2:
                cout << obj->getMin() << "\n";
                break;
            case 3:
                obj->pop();
                break;
            case 4:
                cout << obj->top() << "\n";
                break;
            default: exit(0);
        }
    }
    return 0;
}
