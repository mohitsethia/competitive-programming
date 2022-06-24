#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>

class Solution{
    // define other function in private so not to allow access to that function from main() 
    // otherwise public 
    public:
    returnType function(){
        // start coding here
    };
};

int main(){
    Solution obj;
    string line;
    while(getline(cin, line) &&!line.empty()){
        vector<int> nums;
        if(line.back() == ']'){
            line.pop_back();
            if(line.back() == ' ') line.pop_back();
            reverse(line.begin(), line.end());
            line.pop_back();
            if(line.back() == ' ') line.pop_back();
            reverse(line.begin(), line.end());
        }
        stringstream ss(line);
        int i;
        while(ss >> i){
            nums.push_back(i);
            if(ss.peek() == ',' || ss.peek() == ' ') ss.ignore();
        }
        // cout << obj.function() << "\n";
        // function to be called for array of integers
    }
    return 0;
}
