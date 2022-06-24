#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
public:
    vector<vector<int> > fourSum(vector<int> &num, int target){
        vector<vector<int> > res;
        if(num.empty()){
            return res;
        }
        sort(num.begin(), num.end());
        for(int i = 0; i < (int)num.size(); i++){
            int target3 = target -num[i];
            for(int j = i+1; j < (int)num.size(); j++){
                int target2 = target3 - num[j];
                int front = j+1;
                int back = (int)num.size()-1;
                while(front < back){
                    if(num[front]+num[back] > target2) back--;
                    else if(num[front]+num[back] < target2) front++;
                    else{
                        res.push_back({num[i], num[j], num[front], num[back]});
                        int first = num[front];
                        int second = num[back];
                        while(front < back && num[front] == first) front++;
                        while(front < back && num[back] == second) back--;
                    }
                }
                while(j+1 < (int)num.size() && num[j] == num[j+1]) j++;
            }
            while(i+1 < (int)num.size() && num[i] == num[i+1]) i++;
        }
        return res;
    }
};

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> num(n);
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    Solution *obj = new Solution();
    vector<vector<int> > res = obj->fourSum(num, target);
    for(int i = 0; i < (int)res.size(); i++){
        for(int j = 0; j < 4; j++){
            cout << res[i][j] << " \n"[j == 3];
        }
    }
    return 0;
}
