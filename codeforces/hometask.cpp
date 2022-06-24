#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
#define int long long
void findLargest(int n, vector<int>& v){
    int flag = 0;
    int sum = 0;
    for(int& i: v){
        if(i == 0){
            flag = 1;
        }
        sum += i;
    }
    if(!flag){
        cout << "-1" << endl;
        return;
    }
    sort(v.begin(), v.end(), greater<int>());
    if(v[0] == 0){
        cout << "0" << endl;
        return;
    }
    flag = 0;
    int y = sum%3;
    if(y != 0){
        for(int i = n-1; i >= 0; i--){
            if(v[i]%3 == y){
                v.erase(v.begin()+i);
                flag = 1;
                break;
            }
        }
        if(!flag){
            y = 3-y;
            int cnt = 0;
            for(int i = n-1; i >= 0; i--){
                if(v[i]%3 == y){
                    v.erase(v.begin()+i);
                    cnt++;
                    if(cnt >= 2){
                        break;
                    }
                }
            }
        }
    }
    if(v[0] == 0)
        cout << "0" << endl;
    else{
        for(int& i: v){
            cout << i;
        }
    }
}
int32_t main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int& x: v){
        cin >> x;
    }
    findLargest(n, v);
    return 0;
}
