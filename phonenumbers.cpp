#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> taxi, pizza, girl;
    int countTaxi = 0, countPizza = 0, countGirl = 0, maxTaxi = 0, maxPizza = 0, maxGirl = 0;
    while(n--){
        int k;
        string name;
        cin >> k >> name;
        while(k--){
            string s;
            cin >> s;
            if(s[0] == s[1] && s[0] == s[3] && s[0] == s[4] && s[0] == s[6] && s[0] == s[7]){
                countTaxi++;
                continue;
            }
            bool flag = false;
            if(s[1] < s[0] && s[3] < s[1] && s[4] < s[3] && s[6] < s[4] && s[7] < s[6]){
                flag = true;
            }
            if(flag){
                countPizza++;
                continue;
            }
            countGirl++;
        }
        if(countTaxi > maxTaxi){
            taxi.clear();
            taxi.push_back(name);
            maxTaxi = countTaxi;
        }
        else if(countTaxi == maxTaxi){
            taxi.push_back(name);
            maxTaxi = countTaxi;
        }

        if(countPizza > maxPizza){
            pizza.clear();
            pizza.push_back(name);
            maxPizza = countPizza;
        }
        else if(countPizza == maxPizza){
            pizza.push_back(name);
            maxPizza = countPizza;
        }
        
        if(countGirl > maxGirl){
            girl.clear();
            girl.push_back(name);
            maxGirl = countGirl;
        }
        else if(countGirl == maxGirl){
            girl.push_back(name);
            maxGirl = countGirl;
        }

        countTaxi = 0;
        countPizza = 0;
        countGirl = 0;
        if(n == 1){
            if(!taxi.size()){
                taxi.push_back("");
            }
            if(!pizza.size()){
                pizza.push_back("");
            }
            if(!girl.size()){
                girl.push_back("");
            }
        }
    }
    cout << "If you want to call a taxi, you should call: ";
        for(int i = 0; i < taxi.size() - 1; i++){
            cout << taxi[i] << ", ";
        }
        cout << taxi[taxi.size()-1] << "." << endl;

    cout << "If you want to order a pizza, you should call: ";
        for(int i = 0; i < pizza.size() - 1; i++){
            cout << pizza[i] << ", ";
        }
        cout << pizza[pizza.size()-1] << "." << endl;

    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
        for(int i = 0; i < girl.size() - 1; i++){
            cout << girl[i] << ", ";
        }
        cout << girl[girl.size() - 1] << "." << endl;
    return 0;
}
