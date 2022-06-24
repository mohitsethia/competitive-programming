#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
public:
    string encrypt(string message, string key){
        int i = 0, j = 0;
        string result = "";
        if((int)message.length() == 0 || (int)key.length() == 0) return message;
        while(i < (int)message.length() && j < (int)key.length()){
            int times = key[j] - '0';
            while(times--){
                result += message[i];
            }
            i++;
            j++;
        }
        while(i < (int)message.length()){
            result += message[i++];
        }
        return result;
    }
    
    string decrypt(string message, string key){
        if((int)message.length() == 0 || (int)key.length() == 0) return message;
        int i = 0, j = 0;
        string result = "";
        while(i < (int)message.length() && j < (int)key.length()){
            int times = key[j] - '0';
            result += message[i];
            i += times;
            j++;
        }
        while(i < (int)message.length()){
            result += message[i++];
        }
        return result;
    }
};

int main(){
    int type;
    cin >> type;
    string message;
    cin >> message;
    string key;
    cin >> key;
    Solution *obj = new Solution();
    if(type == 1){
        cout << obj->encrypt(message, key) << "\n";
    }
    else{
        cout << obj->decrypt(message, key) << "\n";
    }
    return 0;
}
