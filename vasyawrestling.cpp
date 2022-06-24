#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<climits>
#include<string>
#include<map>
#include<set>
using namespace std;
#define int long long
int32_t main(){
    int n;
    cin >> n;
    int x, sum = 0;
    vector<int> pos, neg;
    for(int i = 0; i < n; i++){
        cin >> x;
        sum += x;
        if(x > 0){
            pos.push_back(x);
        }
        else{
            neg.push_back(x);
        }
    }
    if(sum > 0){
        cout << "first" << endl;
    }
    else if(sum < 0){   
        cout << "second" << endl;
    }
    else{
        int i = 0, j = 0;
        while(j != neg.size() && i != pos.size()){
            if(pos[i] == -neg[j]){
                i++;
                j++;
                continue;
            }
            if(pos[i] > -neg[j]){
                cout << "first" << endl;
                return 0;
            }
            else if(pos[i] < -neg[j]){
                cout << "second" << endl;
                return 0;
            }
        }
        if(x > 0){
            cout << "first" << endl;
        }
        else{
            cout << "second" << endl;
        }
    }
    return 0;
}
